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
             << tabs << "[3] Encontrar Camino Mínimo (Dijkstra)." << std::endl
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
            Prim();
        }
        else if(opc == "3")
        {
            Dijkstra();
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
                  << tabs << "[4] Agregar arista." << std::endl
                  // << tabs << "[5] Modificar arista." << std::endl
                  << tabs << "[5] Mostrar todos los aristas." << std::endl
                  << tabs << "[6] Regresar." << std::endl << std::endl
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
            NewEdge();
            system("cls");
        }
        /* else if(opc == "5")
        {
            // EditVertex();
            // WIP, TODO
            system("cls");
        } */
        else if(opc == "5"){
            ShowEdges();
            system("cls");
        }
        else if(opc == "6")
        {
            break;
        }
        else if(opc == "load template test_graph"){
            node newNode;
            newNode.setName("A");
            nodeList.push_back(newNode);
            newNode.setName("B");
            nodeList.push_back(newNode);
            newNode.setName("C");
            nodeList.push_back(newNode);
            newNode.setName("D");
            nodeList.push_back(newNode);
            edge newEdge;
            newEdge.setSourceNode(0); // A
            newEdge.setTargetNode(1); // B
            newEdge.setWeight(2);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(0); // A
            newEdge.setTargetNode(2); // C
            newEdge.setWeight(6);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(1); // B
            newEdge.setTargetNode(3); // D
            newEdge.setWeight(6);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(2); // C
            newEdge.setTargetNode(3); // D
            newEdge.setWeight(1);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            system("cls");
        } else if(opc == "load template improved_test_graph"){
            node newNode;
            newNode.setName("A");
            nodeList.push_back(newNode);
            newNode.setName("B");
            nodeList.push_back(newNode);
            newNode.setName("C");
            nodeList.push_back(newNode);
            newNode.setName("D");
            nodeList.push_back(newNode);
            newNode.setName("E");
            nodeList.push_back(newNode);
            newNode.setName("F");
            nodeList.push_back(newNode);
            edge newEdge;
            newEdge.setSourceNode(0); // A
            newEdge.setTargetNode(1); // B
            newEdge.setWeight(2);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(0); // A
            newEdge.setTargetNode(2); // C
            newEdge.setWeight(6);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(1); // B
            newEdge.setTargetNode(3); // D
            newEdge.setWeight(6);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(2); // C
            newEdge.setTargetNode(3); // D
            newEdge.setWeight(1);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(1); // B
            newEdge.setTargetNode(4); // E
            newEdge.setWeight(5);
            newEdge.setBidirectional(true);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(4); // E
            newEdge.setTargetNode(3); // D
            newEdge.setWeight(8);
            newEdge.setBidirectional(true);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(2); // C
            newEdge.setTargetNode(5); // F
            newEdge.setWeight(3);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(5); // F
            newEdge.setTargetNode(3); // D
            newEdge.setWeight(2);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            system("cls");
        } else if(opc == "load template aurora_dijkstra"){
            node newNode;
            newNode.setName("v1");
            nodeList.push_back(newNode);
            newNode.setName("v2");
            nodeList.push_back(newNode);
            newNode.setName("v3");
            nodeList.push_back(newNode);
            newNode.setName("v4");
            nodeList.push_back(newNode);
            newNode.setName("v5");
            nodeList.push_back(newNode);
            newNode.setName("v6");
            nodeList.push_back(newNode);
            newNode.setName("v7");
            nodeList.push_back(newNode);
            edge newEdge;
            newEdge.setSourceNode(0); // v1
            newEdge.setTargetNode(1); // v2
            newEdge.setWeight(3);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(0); // v1
            newEdge.setTargetNode(2); // v3
            newEdge.setWeight(9);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(1); // v2
            newEdge.setTargetNode(2); // v3
            newEdge.setWeight(2);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(2); // v3
            newEdge.setTargetNode(3); // v4
            newEdge.setWeight(7);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(1); // v2
            newEdge.setTargetNode(4); // v5
            newEdge.setWeight(1);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(2); // v3
            newEdge.setTargetNode(4); // v5
            newEdge.setWeight(1);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(4); // v5
            newEdge.setTargetNode(3); // v4
            newEdge.setWeight(5);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(3); // v4
            newEdge.setTargetNode(5); // v6
            newEdge.setWeight(2);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(3); // v4
            newEdge.setTargetNode(6); // v7
            newEdge.setWeight(8);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(4); // v5
            newEdge.setTargetNode(5); // v6
            newEdge.setWeight(9);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(5); // v6
            newEdge.setTargetNode(6); // v7
            newEdge.setWeight(4);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            newEdge.setSourceNode(1); // v2
            newEdge.setTargetNode(3); // v4
            newEdge.setWeight(7);
            newEdge.setBidirectional(false);
            edgeList.push_back(newEdge);
            system("cls");
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
                std::cout << "\n" << tabs << "Aristas: ";
                bool once = false;
                for(size_t j = 0; j < edgeList.size(); j++){
                    if(edgeList[j].getTargetNode() == static_cast<int>(ID - 1) || edgeList[j].getSourceNode() == static_cast<int>(ID - 1)){
                        once = true;
                        std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                        if(edgeList[j].getBidirectional()){
                            std::cout << " <-> ";
                        } else{
                            std::cout << " -> ";
                        }
                        std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                    }
                }
                if(!once){
                    std::cout << "No hay aristas conectando este nodo.";
                }

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
                std::cout << "\n" << tabs << "Aristas: ";
                bool once = false;
                for(size_t j = 0; j < edgeList.size(); j++){
                    if(edgeList[j].getTargetNode() == static_cast<int>(i) || edgeList[j].getSourceNode() == static_cast<int>(i)){
                        once = true;
                        std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                        if(edgeList[j].getBidirectional()){
                            std::cout << " <-> ";
                        } else{
                            std::cout << " -> ";
                        }
                        std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                    }
                }
                if(!once){
                    std::cout << "No hay aristas conectando este nodo.";
                }

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
        std::cout << tabs << "[1] Modificar nombre\n" /*<< tabs << "[2] Modificar aristas\n"*/ << tabs << "[0] Cancelar\n\n" << tabs << "Selección: ";
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
            std::cout << "\n" << tabs << "------------------";
            std::cout << "\n" << tabs << "ID: " << i + 1;
            std::cout << "\n" << tabs << "Nombre: " << nodeList[i].getName();
            std::cout << "\n" << tabs << "Aristas: ";
            bool once = false;
            for(size_t j = 0; j < edgeList.size(); j++){
                if(edgeList[j].getTargetNode() == static_cast<int>(i) || edgeList[j].getSourceNode() == static_cast<int>(i)){
                    once = true;
                    std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                    if(edgeList[j].getBidirectional()){
                        std::cout << " <-> ";
                    } else{
                        std::cout << " -> ";
                    }
                    std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                }
            }
            if(!once){
                std::cout << "No hay aristas conectando este nodo.";
            }
            std::cout << "\n" << tabs << "------------------" << std::endl;
        }
    } else{
        std::cout << "\n" << tabs << "No existe ningún nodo en este grafo." << std::endl << std::endl;
    }


    std::cout << "\n" << tabs << "Presiona cualquier tecla para regresar.";
    getchar();
}

void Menu::NewEdge()
{
    std::string weightString, tabs = "\t\t";
    system("cls");
    std::cout << "\n" << tabs << "Usted está agregando un nuevo aristas, al que se le asignará el ID: " << edgeList.size() + 1 << std::endl << std::endl;

    std::cout << tabs << "Valor/peso/ponderación del arista: ";
    getline(std::cin, weightString);

    if(isInteger(weightString)){
        std::string opc;
        int Weight = stoi(weightString);
        edge newEdge;
        newEdge.setWeight(Weight);
        std::cout << "\n" << tabs << "[1] Agregar arista a nodo existente\n" << tabs << "[2] Agregar arista estático; no será asignado a ningún nodo de manera automática.\n" << tabs << "[0] Cancelar\n\n" << tabs << "Selección: ";
        getline(std::cin, opc);

        if(opc == "1"){ // Agregar arista a nodo existente
            std::string s1, s2, searchType;

            // TODO: Ask if they want to search the node by ID or Name.
            std::cout << "\n" << tabs << "Selecciona el nodo del que parte el arista.";
            std::cout << "\n" << tabs << "Buscar nodo por:\n" << tabs << "[1] ID\n" << tabs << "[2] Nombre\n" << tabs << "[0] Cancelar\n\n" << tabs << "Tipo: ";
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
                        std::cout << "\n" << tabs << "Aristas: ";
                        bool once = false;
                        for(size_t j = 0; j < edgeList.size(); j++){
                            if(edgeList[j].getTargetNode() == static_cast<int>(ID - 1) || edgeList[j].getSourceNode() == static_cast<int>(ID - 1)){
                                once = true;
                                std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                                if(edgeList[j].getBidirectional()){
                                    std::cout << " <-> ";
                                } else{
                                    std::cout << " -> ";
                                }
                                std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                            }
                        }
                        if(!once){
                            std::cout << "No hay aristas conectando este nodo.";
                        }
                        std::cout << "\n" << tabs << "------------------" << std::endl;
                        found = true;
                        newEdge.setSourceNode(static_cast<int>(ID - 1));
                    }
                }
            } else if(searchType == "2"){
                std::string name;
                std::cout << tabs << "Nombre: ";
                getline(std::cin, name);

                for(size_t i = 0; i < nodeList.size(); i++){
                    if(nodeList[i].getName() == name){
                        found = true;
                        std::cout << "\n\n" << tabs << "------------------" << std::endl;
                        std::cout << tabs << "ID: " << i + 1;
                        std::cout << "\n" << tabs << "Nombre: " << nodeList[i].getName();
                        std::cout << "\n" << tabs << "Aristas: ";
                        bool once = false;
                        for(size_t j = 0; j < edgeList.size(); j++){
                            if(edgeList[j].getTargetNode() == static_cast<int>(i) || edgeList[j].getSourceNode() == static_cast<int>(i)){
                                once = true;
                                std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                                if(edgeList[j].getBidirectional()){
                                    std::cout << " <-> ";
                                } else{
                                    std::cout << " -> ";
                                }
                                std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                            }
                        }
                        if(!once){
                            std::cout << "No hay aristas conectando este nodo.";
                        }
                        std::cout << "\n" << tabs << "------------------" << std::endl;
                        newEdge.setSourceNode(static_cast<int>(i));
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
                std::cout << "\n" << tabs << "Selecciona el nodo al que va el arista.";
                std::cout << "\n" << tabs << "Buscar nodo por:\n" << tabs << "[1] ID\n" << tabs << "[2] Nombre\n" << tabs << "[0] Cancelar\n\n" << tabs << "Tipo: ";
                getline(std::cin, searchType);
                found = false;

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
                            std::cout << "\n" << tabs << "Aristas: ";
                            bool once = false;
                            for(size_t j = 0; j < edgeList.size(); j++){
                                if(edgeList[j].getTargetNode() == static_cast<int>(ID - 1) || edgeList[j].getSourceNode() == static_cast<int>(ID - 1)){
                                    once = true;
                                    std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                                    if(edgeList[j].getBidirectional()){
                                        std::cout << " <-> ";
                                    } else{
                                        std::cout << " -> ";
                                    }
                                    std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                                }
                            }
                            if(!once){
                                std::cout << "No hay aristas conectando este nodo.";
                            }
                            std::cout << "\n" << tabs << "------------------" << std::endl;
                            found = true;
                            newEdge.setTargetNode(static_cast<int>(ID - 1));
                        }
                    }
                } else if(searchType == "2"){
                    std::string name;
                    std::cout << tabs << "Nombre: ";
                    getline(std::cin, name);

                    for(size_t i = 0; i < nodeList.size(); i++){
                        if(nodeList[i].getName() == name){
                            found = true;
                            std::cout << "\n\n" << tabs << "------------------" << std::endl;
                            std::cout << tabs << "ID: " << i + 1;
                            std::cout << "\n" << tabs << "Nombre: " << nodeList[i].getName();
                            std::cout << "\n" << tabs << "Aristas: ";
                            bool once = false;
                            for(size_t j = 0; j < edgeList.size(); j++){
                                if(edgeList[j].getTargetNode() == static_cast<int>(i) || edgeList[j].getSourceNode() == static_cast<int>(i)){
                                    once = true;
                                    std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                                    if(edgeList[j].getBidirectional()){
                                        std::cout << " <-> ";
                                    } else{
                                        std::cout << " -> ";
                                    }
                                    std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                                }
                            }
                            if(!once){
                                std::cout << "No hay aristas conectando este nodo.";
                            }
                            std::cout << "\n" << tabs << "------------------" << std::endl;
                            newEdge.setTargetNode(static_cast<int>(i));
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
                    std::cout << "\n" << tabs << "¿Deseas convertir este arista en un arista bidireccional?";
                    std::cout << "\n" << tabs << "[1] Mantener dirección\n" << tabs << "[2] Convertir en bidireccional\n" << tabs << "[0] Cancelar\n\n" << tabs << "Seleccionar: ";
                    getline(std::cin, opc);

                    if(opc == "2"){
                        newEdge.setBidirectional(true);
                    }

                    if(opc == "1" || opc == "2"){
                        edgeList.push_back(newEdge);
                        std::cout << "\n" << tabs << "El arista ha sido agregado.";
                    }
                }
            }
        } else if(opc == "2"){ // Agregar arista estático
            bool valid = false;

            if(isInteger(weightString)){
                std::string opc;
                int Weight = stoi(weightString);
                newEdge.setWeight(Weight);

                std::cout << "\n" << tabs << "¿Deseas convertir este arista en un arista bidireccional?";
                std::cout << "\n" << tabs << "[1] Mantener dirección\n" << tabs << "[2] Convertir en bidireccional\n" << tabs << "[0] Cancelar\n\n" << tabs << "Seleccionar: ";
                getline(std::cin, opc);

                if(opc == "1" || opc == "2"){
                    if(opc == "2"){
                        newEdge.setBidirectional(true);
                    }
                    valid = true;
                    newEdge.setSourceNode(-1);
                    newEdge.setTargetNode(-1);
                }
            }

            if(valid){
                std::cout << std::endl << tabs << "El arista ha sido agregado de manera estática.";
                edgeList.push_back(newEdge);
             } else{
               std::cout << std::endl << tabs << "El arista no ha sido agregado.";
             }
        } else{
            std::cout << std::endl << tabs << "Se ha cancelado el proceso.";
        }
    } else{
        std::cout << std::endl << tabs << "El valor ingresado no es válido.";
    }

    getchar();

}

void Menu::ShowEdges()
{
    std::string tabs = "\t\t";
    system("cls");

    if(edgeList.size() != 0){
        std::cout << "\n" << tabs << "Los siguientes aristas se encuentran cargados en el grafo:" << std::endl << std::endl;

        for(size_t i = 0; i < edgeList.size(); i++){
            std::cout << "\n" << tabs << "------------------";
            std::cout << "\n" << tabs << "ID: " << i + 1;
            if(edgeList[i].getSourceNode() != -1){
                std::cout << "\n" << tabs << "Nodo origen: " << nodeList[static_cast<size_t>(edgeList[i].getSourceNode())].getName() << " (ID: " << edgeList[i].getSourceNode() + 1 << ")";
            } else{
                std::cout << "\n" << tabs << "Nodo origen: No asignado.";
            }

            if(edgeList[i].getTargetNode() != -1){
                std::cout << "\n" << tabs << "Nodo destino: " << nodeList[static_cast<size_t>(edgeList[i].getTargetNode())].getName() << " (ID: " << edgeList[i].getTargetNode() + 1 << ")";
            } else{
                std::cout << "\n" << tabs << "Nodo destino: No asignado.";
            }

            std::cout << "\n" << tabs << "Valor: " << edgeList[i].getWeight();

            if(edgeList[i].getBidirectional()){
                std::cout << "\n" << tabs << "* Este arista es bidireccional.";
            }
        }
        std::cout << "\n" << tabs << "------------------" << std::endl;
    } else{
        std::cout << "\n" << tabs << "No existe ningún arista en este grafo." << std::endl << std::endl;
    }

    std::cout << "\n" << tabs << "Presiona cualquier tecla para regresar.";
    getchar();
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

void Menu::Prim()
{
    std::string opc, tabs = "\t\t";
    system("cls");

    std::cout << "\n" << tabs << "Prim es un algoritmo para grafos no dirigidos, convexos y ponderados que permite encontrar un árbol de expansión mínima para el grafo." << std::endl;
    std::cout << tabs << "Consideraciones al usar este algoritmo: " << std::endl;
    std::cout << "* El grafo se considerará no dirigido, es decir, se ignorará la configuración de direccionalidad de los aristas." << std::endl;
    std::cout << "* El grafo debe ser conexo, de no serlo, el comportamiento de este algoritmo será indefinido, pues solo se considerará un subgrafo y el resultado no será el esperado." << std::endl;

    std::cout << "\n" << tabs << "[1] Ejecutar Prim en este grafo\n" << tabs << "[0] Cancelar\n\n" << tabs << "Selección: ";
    getline(std::cin, opc);


    if(opc == "1"){
        if(nodeList.size() == 0 || edgeList.size() == 0){
            std::cout << "\n" << tabs << "El grafo es inválido.\n";
        } else{
            system("cls");

            std::vector<std::vector<int>> adjacencyMatrix(nodeList.size(), std::vector<int>(nodeList.size()));

            for(size_t k = 0; k < nodeList.size(); k++){ // Initialize matrix with 0s
                for(size_t l = 0; l < nodeList.size(); l++){
                    adjacencyMatrix[k][l] = 0;
                }
            }

            for(size_t k = 0; k < edgeList.size(); k++){
                /* DEBUG ONLY std::cout << "\n" << edgeList[k].getSourceNode();
                std::cout << "\n" << edgeList[k].getTargetNode();
                std::cout << "\n\n"; */

                if(edgeList[k].getSourceNode() != -1 && edgeList[k].getTargetNode() != -1){
                    adjacencyMatrix[static_cast<size_t>(edgeList[k].getSourceNode())][static_cast<size_t>(edgeList[k].getTargetNode())] = edgeList[k].getWeight();
                    adjacencyMatrix[static_cast<size_t>(edgeList[k].getTargetNode())][static_cast<size_t>(edgeList[k].getSourceNode())] = edgeList[k].getWeight(); // Symmetry enforcement [graph has to be bidirectional for Prim]
                }
            }

            std::cout << "\nMatriz de adyacencia: " << std::endl << std::endl << "\t";

            for(size_t k = 0; k < nodeList.size(); k++){ // Print matrix
                for(size_t l = 0; l < nodeList.size(); l++){
                    std::cout << adjacencyMatrix[k][l] << " ";
                }
                std::cout << "\n\t";
            }





            size_t edgeAmount = 0;
            std::vector<bool> selected;
            for (size_t i = 1; i <= nodeList.size(); i++){ // false initialize selected vector
                    selected.push_back(false);
            }

            selected[0] = true;
            size_t x = 0, y = 0;
            int totalCost = 0;


            std::cout << "\n\nÁrbol de expansión mínima: \n";
            std::cout << "\tNodo 1 - Nodo 2 : Ponderación\n";
            while(edgeAmount < nodeList.size() - 1){
                int min = -1;
                x = 0;
                y = 0;

                for(size_t i = 0; i < nodeList.size(); i++){
                    if(selected[i]){
                        for(size_t j = 0; j < nodeList.size(); j++){
                            if(!selected[j] && adjacencyMatrix[i][j]){
                                if(min == -1){
                                    min = adjacencyMatrix[i][j] + 1;
                                }
                                if(min > adjacencyMatrix[i][j]){
                                    min = adjacencyMatrix[i][j];
                                    x = i;
                                    y = j;
                                }
                            }
                        }
                    }
                }

                std::cout << "\t" << nodeList[x].getName() <<  " - " << nodeList[y].getName() << " :  " << adjacencyMatrix[x][y];
                std::cout << std::endl;
                selected[y] = true;
                edgeAmount++;
                totalCost += adjacencyMatrix[x][y];
            }


            std::cout << "El costo total de este recorrido es: " << totalCost;
        }
     }

    std::cout << "\n" << tabs << "Presiona cualquier tecla para regresar.";
    getchar();
}

void Menu::Dijkstra()
{
    std::string opc, tabs = "\t\t";
    system("cls");

    std::cout << "\n" << tabs << "Dijkstra es un algoritmo para grafos dirigidos, convexos y ponderados que permite encontrar camínos mínimos entre todos los nodos del grafo." << std::endl;
    std::cout << tabs << "Consideraciones al usar este algoritmo: " << std::endl;
    std::cout << "* El grafo debe ser conexo, de no serlo, el comportamiento de este algoritmo será indefinido, pues solo se considerará un subgrafo y el resultado no será el esperado." << std::endl;

    std::cout << "\n" << tabs << "[1] Ejecutar Dijkstra en este grafo\n" << tabs << "[0] Cancelar\n\n" << tabs << "Selección: ";
    getline(std::cin, opc);

    if(opc == "1"){
        if(nodeList.size() == 0 || edgeList.size() == 0){
            std::cout << "\n" << tabs << "El grafo es inválido.\n";
        } else{
            std::cout << "\n" << tabs << "Los siguientes nodos se encuentran cargados en el grafo:" << std::endl << std::endl;

            for(size_t i = 0; i < nodeList.size(); i++){
                std::cout << "\n" << tabs << "------------------";
                std::cout << "\n" << tabs << "ID: " << i + 1;
                std::cout << "\n" << tabs << "Nombre: " << nodeList[i].getName();
                std::cout << "\n" << tabs << "Aristas: ";
                bool once = false;
                for(size_t j = 0; j < edgeList.size(); j++){
                    if(edgeList[j].getTargetNode() == static_cast<int>(i) || edgeList[j].getSourceNode() == static_cast<int>(i)){
                        once = true;
                        std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                        if(edgeList[j].getBidirectional()){
                            std::cout << " <-> ";
                        } else{
                            std::cout << " -> ";
                        }
                        std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                    }
                }
                if(!once){
                    std::cout << "No hay aristas conectando este nodo.";
                }
                std::cout << "\n" << tabs << "------------------" << std::endl;
            }

            std::string IDString;
            std::cout << tabs << "Seleccione el nodo desde el cual iniciar (ID): ";
            getline(std::cin, IDString);
            bool valid = false;
            size_t src = 0;

            if(isInteger(IDString)){
                size_t ID = stoul(IDString);
                if(ID > nodeList.size()){
                    std::cout << std::endl << tabs << "Nodo no encontrado.";
                } else{
                    std::cout << "\n\n" << tabs << "------------------" << std::endl;
                    std::cout << tabs << "ID: " << ID;
                    std::cout << "\n" << tabs << "Nombre: " << nodeList[ID - 1].getName();
                    std::cout << "\n" << tabs << "Aristas: ";
                    for(size_t j = 0; j < edgeList.size(); j++){
                        if(edgeList[j].getTargetNode() == static_cast<int>(ID - 1) || edgeList[j].getSourceNode() == static_cast<int>(ID - 1)){
                            std::cout << nodeList[static_cast<size_t>(edgeList[j].getSourceNode())].getName();
                            if(edgeList[j].getBidirectional()){
                                std::cout << " <-> ";
                            } else{
                                std::cout << " -> ";
                            }
                            std::cout << nodeList[static_cast<size_t>(edgeList[j].getTargetNode())].getName() << " (" << edgeList[j].getWeight() << ") | ";
                        }
                    }
                    src = ID - 1;
                    valid = true;
                }
            } else{
               std::cout << std::endl << tabs << "Nodo no válido.";
            }

            if(valid){
                system("cls");
                std::vector<std::vector<int>> adjacencyMatrix(nodeList.size(), std::vector<int>(nodeList.size()));

                for(size_t k = 0; k < nodeList.size(); k++){ // Initialize matrix with 0s
                    for(size_t l = 0; l < nodeList.size(); l++){
                        adjacencyMatrix[k][l] = 0;
                    }
                }


                for(size_t k = 0; k < edgeList.size(); k++){
                    /* DEBUG ONLY std::cout << "\n" << edgeList[k].getSourceNode();
                    std::cout << "\n" << edgeList[k].getTargetNode();
                    std::cout << "\n\n"; */

                    if(edgeList[k].getSourceNode() != -1 && edgeList[k].getTargetNode() != -1){
                        adjacencyMatrix[static_cast<size_t>(edgeList[k].getSourceNode())][static_cast<size_t>(edgeList[k].getTargetNode())] = edgeList[k].getWeight();
                        if(edgeList[k].getBidirectional()){
                            adjacencyMatrix[static_cast<size_t>(edgeList[k].getTargetNode())][static_cast<size_t>(edgeList[k].getSourceNode())] = edgeList[k].getWeight(); // Symmetry if edge is bidirectional
                        }

                    }
                }

                std::cout << "\n\tMatriz de adyacencia: " << std::endl << std::endl << "\t";

                for(size_t k = 0; k < nodeList.size(); k++){ // Print matrix
                    for(size_t l = 0; l < nodeList.size(); l++){
                        std::cout << adjacencyMatrix[k][l] << " ";
                    }
                    std::cout << "\n\t";
                }


                std::vector<int> dist;
                std::vector<bool> selected;
                for (size_t i = 0; i < nodeList.size(); i++){ // false initialize selected vector, infinite initialize dist vector
                        dist.push_back(INT_MAX);
                        selected.push_back(false);
                }

                dist[src] = 0;
                selected[0] = true;

                std::cout << "\n" << tabs;
                for(size_t v = 0; v < nodeList.size(); v++){
                    if(v != src){
                        std::cout << "D[" << nodeList[v].getName() << "]\t";
                    }
                }

                size_t k = src;
                size_t potK = k;
                int potKv = INT_MAX;

                for(size_t checkedNodes = 0; checkedNodes < nodeList.size(); checkedNodes++){
                    selected[k] = true;
                    potKv = INT_MAX;
                    std::cout << "\n\t" << nodeList[k].getName();
                    for(size_t v = 0; v < nodeList.size(); v++){
                        if(v != src){
                            if(adjacencyMatrix[k][v]){
                                if(adjacencyMatrix[k][v] < dist[v]){
                                    if(adjacencyMatrix[k][v] + dist[k] < dist[v]){
                                        dist[v] = adjacencyMatrix[k][v] + dist[k];
                                    }
                                }
                            }

                            if(dist[v] < static_cast<int>(potKv) && !selected[v]){
                                potK = v;
                                potKv = dist[v];
                            }
                        }
                    }
                    for(size_t y = 0; y < dist.size(); y++){
                        if(y != src){
                            if(dist[y] != INT_MAX){
                                std::cout << "\t" << dist[y];
                            } else{
                                std::cout << "\t ∞";
                            }

                        }
                    }
                    k = potK;
                }
            }
        }
     }

    std::cout << "\n\n\n" << tabs << "Presiona cualquier tecla para regresar.";
    getchar();
}
