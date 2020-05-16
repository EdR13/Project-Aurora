#include "menu.h"

Menu::Menu()
{

}

void Menu::menu()
{
    std::string opc, tabs = "\t\t";
    while(true)
    {
        system("cls");
        std::cout << "\n" << tabs << "Menú Principal" << std::endl << std::endl << std::endl << std::endl;
        std::cout << tabs << "[1] Modificar grafo." << std::endl
             << tabs << "[2] Crear Árbol de Expansión Mínima (Prim)." << std::endl
             << tabs << "[3] Encontrar Camino Mínimo (Dijsktra)." << std::endl
             << tabs << "[4] Salir del programa." << std::endl << std::endl
             << tabs << "Elección: ";
        getline(std::cin, opc);
        if(opc == "1")
        {
            system("cls");
            AddGraph();
        }
        else if (opc == "2")
        {

        }
        else if(opc == "3")
        {

        }
        else if(opc == "4")
        {
            break;
        }
        else
        {
            std::cout << std::endl << tabs << "Has introducido un valor no válido, intenta de nuevo.";
            getchar();
            opc.clear();
        }
    }

}

void Menu::AddGraph()
{
    std::string opc, tabs = "\t\t";
    while(true)
    {
        system("cls");
        std::cout << "\n" << tabs << "Características del grafo" << std::endl << std::endl << std::endl << std::endl;
        std::cout << tabs << "[1] Agregar nodo." << std::endl
                  << tabs << "[2] Modificar nodo." << std::endl
                  << tabs << "[3] Mostrar todos los nodos." << std::endl
                  << tabs << "[4] Agregar vértice." << std::endl
                  << tabs << "[5] Modificar vértice." << std::endl
                  << tabs << "[6] Mostrar todos los vértices." << std::endl
                  << tabs << "[7] Regresar." << std::endl << std::endl
                  << tabs << "Elección: ";
        getline(std::cin, opc);
        if(opc == "1")
        {
            NewNode();
            system("cls");
        }
        else if (opc == "2")
        {
            // EditNode()
            // Not accesible yet as its behavior is undefined
        }
        else if(opc == "3")
        {
            ShowNodes();
        }
        else if(opc == "4")
        {

        }
        else if(opc == "7")
        {
            break;
        }
        else
        {
            std::cout << std::endl << tabs << "Has introducido un valor no válido, intenta de nuevo.";
            getchar();
            opc.clear();
        }
    }

}

void Menu::NewNode()
{
    std::string name, tabs = "\t\t";
    system("cls");
    std::cout << "\n" << tabs << "Usted está agregando un nuevo nodo, al que se le asignará el ID: " << nodeList.size() << std::endl << std::endl;
    std::cout << "\n" << tabs << "Puede ingresar '0' o 'cancel' para cancelar sin agregar el nodo." << std::endl;

    std::cout << tabs << "Nombre del nodo: ";
    getline(std::cin, name);

    if(name != "0" && name != "cancel" && name != ""){
        node newNode;
        newNode.setName(name);
        nodeList.push_back(newNode);
        system("cls");
        std::cout << std::endl << tabs << "Se ha agregado el nodo '" << name << "' con el ID " << nodeList.size() << ".";
        getchar();
    }
}


void Menu::EditNode()
{
    std::string opc, tabs = "\t\t";
    while(true)
    {
        system("cls");
        std::cout << "\n" << tabs << "Características del grafo" << std::endl << std::endl << std::endl << std::endl;
        std::cout << tabs << "[1] Agregar nodo." << std::endl
                  << tabs << "[2] Modificar nodo." << std::endl
                  << tabs << "[3] Mostrar todos los nodos." << std::endl
                  << tabs << "[4] Agregar vértice." << std::endl
                  << tabs << "[5] Modificar vértice." << std::endl
                  << tabs << "[6] Mostrar todos los vértices." << std::endl
                  << tabs << "[7] Regresar." << std::endl << std::endl
                  << tabs << "Elección: ";
        getline(std::cin, opc);
        if(opc == "1")
        {
            EditNode();
            system("cls");
        }
        else if (opc == "2")
        {

        }
        else if(opc == "3")
        {

        }
        else if(opc == "4")
        {

        }
        else if(opc == "7")
        {
            break;
        }
        else
        {
            std::cout << std::endl << tabs << "Has introducido un valor no válido, intenta de nuevo.";
            getchar();
            opc.clear();
        }
    }

}

void Menu::ShowNodes()
{
    std::string tabs = "\t\t";
    system("cls");

    if(nodeList.size() != 0){
        std::cout << "\n" << tabs << "Los siguientes nodos se encuentran cargados en el grafo:" << std::endl << std::endl;

        for(size_t i = 0; i < nodeList.size(); i++){
            std::cout << "\n\n" << tabs << "ID: " << i + 1;
            std::cout << "\n" << tabs << "Nombre: " << nodeList[i].getName();
            std::cout << "\n" << tabs << "Vertices: " << "THIS IS PENDING";
            // TODO: This should loop through all vertices out of nodeList[i].vertices and print both nodes, weight and direction.
            std::cout << "\n" << tabs << "------------------" << std::endl;

        }
    } else{
        std::cout << "\n" << tabs << "No existe ningún nodo en este grafo." << std::endl << std::endl;
    }


    std::cout << "\n" << tabs << "Presiona cualquier tecla para regresar.";
    getchar();
}
