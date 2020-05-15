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
        std::cout << tabs << "[1] Agregar un grafo." << std::endl
             << tabs << "[2] Crear Árbol de Expansión Mínima (Prim)." << std::endl
             << tabs << "[3] Encontrar Camino Mínimo (Djisktra)." << std::endl
             << tabs << "[4] Salir del Programa." << std::endl << std::endl
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
            std::cout << std::endl << tabs << "Haz introducido un valor no válido, intenta de nuevo.";
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
        std::cout << "\n" << tabs << "Agregar un grafo" << std::endl << std::endl << std::endl << std::endl;
        std::cout << tabs << "[1] Agregar nodo." << std::endl
                  << tabs << "[2] Modificar nodo." << std::endl
                  << tabs << "[3] Agregar Vértice." << std::endl
                  << tabs << "[4] Modificar Vértice." << std::endl
                  << tabs << "[5] Regresar." << std::endl << std::endl
                  << tabs << "Elección: ";
        getline(std::cin, opc);
        if(opc == "1")
        {
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
        else if(opc == "5")
        {
            break;
        }
        else
        {
            std::cout << std::endl << tabs << "Haz introducido un valor no válido, intenta de nuevo.";
            getchar();
            opc.clear();
        }
    }

}


