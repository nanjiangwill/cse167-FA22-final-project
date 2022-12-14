/**************************************************
Scene.cpp contains the implementation of the draw command
*****************************************************/
#include "RTScene.h"
#include "RTCube.h"
#include "RTObj.h"
#include "RTScene.inl"
// The scene init definition
//#include "Scene.inl"

using namespace glm;
using namespace std;




void RTScene::buildTriangleSoup(void){
    // Pre-draw sequence: assign uniforms that are the same for all Geometry::draw call.  These uniforms include the camera view, proj, and the lights.  These uniform do not include modelview and material parameters.
    camera->computeMatrices();


    // Define stacks for depth-first search (DFS)
    std::stack<RTNode *> dfs_stack;
    std::stack<mat4> matrix_stack; // HW3: You will update this matrix_stack during the depth-first search while loop.

    // Initialize the current state variable for DFS
    RTNode *cur = node["world"];  // root of the tree
    mat4 cur_VM = camera->view; // HW3: You will update this current modelview during the depth first search.  Initially, we are at the "world" node, whose modelview matrix is just camera's view matrix.

    //mat4 cur_VM = glm::mat4(1.0f);
    //  HW3: The following is the beginning of the depth-first search algorithm.
    //  HW3: The depth-first search for the node traversal has already been implemented (cur, dfs_stack).
    //  HW3: All you have to do is to also update the states of (cur_VM, matrix_stack) alongside the traversal.  You will only need to modify starting from this line.
    dfs_stack.push(cur);
    /**
     * TODO: (HW3 hint: you should do something here)
     */
    matrix_stack.push(cur_VM);
    // Compute total number of connectivities in the graph; this would be an upper bound for
    // the stack size in the depth first search over the directed acyclic graph
    int total_number_of_edges = 0;
    for (const auto &n : node) total_number_of_edges += n.second->childnodes.size();

    // If you want to print some statistics of your scene graph
    // std::cout << "total numb of nodes = " << node.size() << std::endl;
    // std::cout << "total number of edges = " << total_number_of_edges << std::endl;

    while (!dfs_stack.empty())
    {
        // Detect whether the search runs into infinite loop by checking whether the stack is longer than the number of edges in the graph.
        if (dfs_stack.size() > total_number_of_edges)
        {
            std::cerr << "Error: The scene graph has a closed loop." << std::endl;
            exit(-1);
        }

        // top-pop the stacks
        cur = dfs_stack.top();
        dfs_stack.pop();
        /**
         * TODO: (HW3 hint: you should do something here)
         */
        cur_VM = matrix_stack.top();
        matrix_stack.pop();
        // draw all the models at the current node
        for (size_t i = 0; i < cur->models.size(); i++)
        {
            // Prepare to draw the geometry. Assign the modelview and the material.

            /**
             * TODO: (HW3 hint: you should do something here)
             */
            glm::mat4 curModelView = cur_VM * cur->modeltransforms[i];
            glm::mat3 invTransMV = glm::inverse(glm::transpose(mat3(curModelView)));
            Material *curMaterial = cur->models[i]->material;
            std::vector<Triangle> triangleElement = cur->models[i]->geometry->elements;
            // cout << "triangleElement size is " << triangleElement.size() << endl;
            for (int i = 0; i < triangleElement.size(); i++)
            {
                //cout << "test triangle" << endl;
                Triangle transformedTri;

                glm::vec4 currProd = curModelView * glm::vec4(triangleElement[i].P[0], 1);
                transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
                currProd = curModelView * glm::vec4(triangleElement[i].P[1], 1);
                transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
                currProd = curModelView * glm::vec4(triangleElement[i].P[2], 1);
                transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
                transformedTri.N.push_back(invTransMV * triangleElement[i].N[0]);
                transformedTri.N.push_back(invTransMV * triangleElement[i].N[1]);
                transformedTri.N.push_back(invTransMV * triangleElement[i].N[2]);

                transformedTri.material = curMaterial;
                triangle_soup.push_back(transformedTri);
            }
        }

        // Continue the DFS: put all the child nodes of the current node in the stack
        for (size_t i = 0; i < cur->childnodes.size(); i++)
        {
            dfs_stack.push(cur->childnodes[i]);
            /**
             * TODO: (HW3 hint: you should do something here)
             */
            matrix_stack.push(cur_VM * cur->childtransforms[i]);
        }
    }
}
