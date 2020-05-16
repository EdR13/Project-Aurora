#include "menu.h"


bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

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
            EditNode();
            system("cls");
        }
        else if(opc == "3")
        {
            ShowNodes();
            system("cls");
        }
        else if(opc == "4")
        {
            // NewVertex();
            // Disabled while its behavior is undefined. WIP, TODO.
            system("cls");
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
        system("cls");
        if(!isUsed(name)){
            node newNode;
            newNode.setName(name);
            nodeList.push_back(newNode);
            std::cout << std::endl << tabs << "Se ha agregado el nodo '" << name << "' con el ID " << nodeList.size() << ".";
        } else{
            std::cout << std::endl << tabs << "El nombre del nodo ya existe, intente con un nombre distinto.";

        }
        getchar();
    }
}


void Menu::EditNode()
{
    size_t aux = 0;
    std::string searchType, tabs = "\t\t";
    system("cls");
    std::cout << "\n" << tabs << "Para modificar un nodo, puede buscarlo por ID o por nombre." << std::endl;

    std::cout << tabs << "Seleccione el tipo de búsqueda:\n" << tabs << "[1] ID\n" << tabs << "[2] Nombre\n" << tabs << "[0] Cancelar\n\n" << tabs << "Tipo: ";
    getline(std::cin, searchType);
    bool found = false;

    if(searchType == "1"){
        std::string IDString;
        std::cout << tabs << "ID: ";
        getline(std::cin, IDString);

        if(isInteger(IDString)){
            size_t ID = stoul(IDString);
            if(ID > nodeList.size()){
                std::cout << std::endl << tabs << "Nodo no encontrado.";
            } else{
                std::cout << "\n\n" << tabs << "------------------" << std::endl;
                std::cout << tabs << "ID: " << ID;
                std::cout << "\n" << tabs << "Nombre: " << nodeList[ID - 1].getName();
                std::cout << "\n" << tabs << "Vertices: " << "THIS IS PENDING";
                // TODO: This should loop through all vertices out of nodeList[i].vertices and print both nodes, weight and direction.
                std::cout << "\n" << tabs << "------------------" << std::endl;
                found = true;
                aux = ID - 1;
            }
        }
    } else if(searchType == "2"){
        std::string name;
        std::cout << tabs << "Nombre: ";
        getline(std::cin, name);

        for(size_t i = 0; i < nodeList.size(); i++){
            if(nodeList[i].getName() == name){
                found = true;
                aux = i;
                std::cout << "\n\n" << tabs << "------------------" << std::endl;
                std::cout << tabs << "ID: " << i + 1;
                std::cout << "\n" << tabs << "Nombre: " << nodeList[i].getName();
                std::cout << "\n" << tabs << "Vertices: " << "THIS IS PENDING";
                // TODO: This should loop through all vertices out of nodeList[i].vertices and print both nodes, weight and direction.
                std::cout << "\n" << tabs << "------------------" << std::endl;
                i = nodeList.size(); // finish loop
            }
        }
        if(!found){
           std::cout << std::endl << tabs << "Nodo no encontrado.";
        }

    } else{
        std::cout << tabs << "Tipo de búsqueda no válido.";
    }

    if(found){
        std::string opc;
        std::cout << "\n" << tabs << "Seleccione lo que desee hacer." << std::endl << std::endl;
        std::cout << tabs << "[1] Modificar nombre\n" << tabs << "[2] Modificar vértices\n" << tabs << "[0] Cancelar\n\n" << tabs << "Selección: ";
        getline(std::cin, opc);

        if(opc == "1"){
            std::string name;
            std::cout << tabs << "Nombre del nodo: ";
            getline(std::cin, name);

            if(name != ""){
                if(!isUsed(name)){
                    nodeList[aux].setName(name);
                    std::cout << std::endl << tabs << "Se ha modificado correctamente el nodo '" << name << "' con el ID " << aux + 1 << ".";
                } else{
                    std::cout << std::endl << tabs << "El nombre del nodo ya existe, intente con un nombre distinto.";
                }
            } else{
                std::cout << std::endl << tabs << "El nombre del nodo no es válido.";
            }
        } else if(opc == "2"){
            // TODO
        }
        if(opc != "0"){
            getchar();
        }
    } else{
      getchar();
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

void Menu::NewVertex()
{
    std::string weightString, tabs = "\t\t";
    system("cls");
    std::cout << "\n" << tabs << "Usted está agregando un nuevo vértice, al que se le asignará el ID: " << vertexList.size() << std::endl << std::endl;
    std::cout << "\n" << tabs << "Puede ingresar '0' o 'cancel' para cancelar sin agregar el vértice." << std::endl;

    std::cout << tabs << "Valor/peso/ponderación del vértice: ";
    getline(std::cin, weightString);

    if(isInteger(weightString)){
        std::string opc;
        size_t Weight = stoul(weightString);
        std::cout << tabs << "[1] Agregar vértice a nodo existente\n" << tabs << "[2] Agregar vértice estático; no será asignado a ningún nodo de manera automática.\n" << tabs << "[0] Cancelar\n\n" << tabs << "Selección: ";
        getline(std::cin, opc);

        if(opc == "1"){ // Agregar vértice a nodo existente
            size_t n1 = nodeList.size(), n2 = nodeList.size();
            std::string s1, s2;

            // TODO: Ask if they want to search the node by ID or Name.


            std::cout << tabs << ": ";
            getline(std::cin, s1);

            /* if(isInteger(IDString)){
                size_t ID = stoul(IDString);
                if(ID > nodeList.size()){
                    std::cout << std::endl << tabs << "Nodo no encontrado.";
                } */

        } else if(opc == "2"){ // Agregar vértice estático

        } else{

        }
    } else{
        std::cout << std::endl << tabs << "El valor ingresado no es válido.";
    }
}

bool Menu::isUsed(const std::string &name)
{
   for(size_t i = 0; i < nodeList.size(); i++){
       if(nodeList[i].getName() == name){
           return true;
       }
   }
   return false;
}
