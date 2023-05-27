#include "omnimath.h"

// Options générales
#define TROUVER_REGLE_FONCTION 1

// Options "Trouver la règle d'une fonction"
#define F_R_VALEUR_ABSOLUE 1

// Options "Valeur absolue : options pour trouver la règle"
#define F_R_VALEUR_ABSOLUE_POINT_SOMMET 1
#define F_R_VALEUR_ABSOLUE_2POINTS_ORD_POINT 2
#define F_R_VALEUR_ABSOLUE_3POINTS 3

int main() {
    std::list<std::string> options = { "Trouver la règle d'une fonction", "" };
    int option = imprimerOptions(options);
    if(option == TROUVER_REGLE_FONCTION) {
        options = { "Valeur absolue "};
        imprimerOptions(options);
        if(option == F_R_VALEUR_ABSOLUE) {
            std::string fn = TRFVA();
            std::cout << std::endl << "=> " << fn << std::endl;
        }
    }
}

int imprimerOptions(std::list<std::string> options) {
    std::cout << "Options:" << std::endl;
    {
        int i = 1;
        for(std::list<std::string>::iterator iter = options.begin(); iter != options.end(); iter++) {
            std::cout << std::to_string(i) << ". " << *iter << std::endl;
            i++;
        }
        i = 0;
    }

    int option = 0;
    std::cout << "Choisir: ";
    while(option <= 0) {
        std::cin >> option;
    }
    std::cout << std::endl;

    return option;
}

// Trouver la Règle d'une Fonction Valeur Absolue
// Forme étudiée en classe : f(x) = a |(x - h)| + k
std::string TRFVA() {
    std::list<std::string> options = { "À partir d'un point et d'un sommet", "À partir de deux points ayant la même ordonnée et un autre point", "Avec trois points quelconques" };
    int option = imprimerOptions(options);
    if(option == F_R_VALEUR_ABSOLUE_POINT_SOMMET) {
        float x;
        float y;
        float h;
        float k;
        float a;

        // Recueillir les données
        std::cout << "Point (x): "; std::cin >> x;
        std::cout << "Point (y): "; std::cin >> y;
        std::cout << "Sommet (x): "; std::cin >> h;
        std::cout << "Sommet(y): "; std::cin >> k;
        
        // Trouver le paramètre 'a'
        a = (y - k)/abs(x - h);

        // Fonction
        std::string f;
        f = "f(x) = " + std::to_string(a) + "|" + "x" + " - " + std::to_string(h) + "|" + " + " + std::to_string(k);

        return(f);
    }
    else if(option == F_R_VALEUR_ABSOLUE_2POINTS_ORD_POINT) {
        float x;
        float y;
        float x_ord_1;
        float y_ord_1;
        float x_ord_2;
        float y_ord_2;
        float h;
        float k;
        float a;

        // Recueillir les données
        std::cout << "Point 1 avec la même ordonnée (x): "; std::cin >> x_ord_1;
        std::cout << "Point 1 avec la même ordonnée (y): "; std::cin >> y_ord_1;
        std::cout << "Point 2 avec la même ordonnée (x): "; std::cin >> x_ord_2;
        std::cout << "Point 2 avec la même ordonnée (y): "; std::cin >> y_ord_2;
        std::cout << "Point 3 quelconque (x): "; std::cin >> x;
        std::cout << "Point 3 quelconque (y): "; std::cin >> y;

        // Valeur de 'h' : moyenne de l'abscisse des deux points ayant la même ordonnée
        h = (x_ord_1 + x_ord_2)/2;
        // Valeur de la pente de la droite dont on a un minimum de deux points
        if(x < h) {
            if(x < x_ord_1) {
                a = (y_ord_1 - y)/(x_ord_1 - x);
            }
            else {
                a = (y - y_ord_1)/(x - x_ord_1);
            }

            // Signe
            if(y < y_ord_1) {
                a = -a;
            }
        }
        else {
            if(x < x_ord_2) {
                a = (y_ord_2 - y)/(x_ord_2 - x);
            }
            else {
                a = (y - y_ord_2)/(x - x_ord_2);
            }

            // Signe
            if(y > y_ord_2) {
                a = -a;
            }
        }

        // Valeur de 'k'
        k = -(a * abs(x-h)-y);

        // Fonction
        std::string f;
        f = "f(x) = " + std::to_string(a) + "|" + "x" + " - " + std::to_string(h) + "|" + " + " + std::to_string(k);

        return(f);
    }
    else if(option == F_R_VALEUR_ABSOLUE_3POINTS) {
        float x_1;
        float y_1;
        float x_2;
        float y_2;
        float x_3;
        float y_3;
        float h;
        float k;
        float a;
        float b_1;
        float b_2;

        // Recueillir les données
        std::cout << "Point 1 quelconque (x): "; std::cin >> x_1;
        std::cout << "Point 1 quelconque (y): "; std::cin >> y_1;
        std::cout << "Point 2 quelconque (x): "; std::cin >> x_2;
        std::cout << "Point 2 quelconque (y): "; std::cin >> y_2;
        std::cout << "Point 3 quelconque (x): "; std::cin >> x_3;
        std::cout << "Point 3 quelconque (y): "; std::cin >> y_3;

        // Deux extrêmes
        float ex_x_1;
        float ex_y_1;
        float ex_x_2;
        float ex_y_2;

        // Point entre les deux
        float e_x_1;
        float e_y_1;

        std::vector<float> list_x = { x_1, x_2, x_3 };
        std::vector<float> list_y = { y_1, y_2, y_3 };
        std::sort(list_x.begin(), list_x.end());
        
        // Points
        // x
        ex_x_1 = list_x[0];
        e_x_1 = list_x[1];
        ex_x_2 = list_x[2];
        
        // std::cout << std::endl << "x_1: " << std::to_string(x_1) << " x_2: " << std::to_string(x_2) << " x_3: " << std::to_string(x_3) << std::endl;
        // std::cout << std::endl << "y_1: " << std::to_string(y_1) << " y_2: " << std::to_string(y_2) << " y_3: " << std::to_string(y_3) << std::endl;

        // Ordonner les ordonnées
        {
            if(list_x[0] == x_1) {
                list_y[0] = y_1;
            }
            else if(list_x[1] == x_1) {
                list_y[1] = y_1;
            }
            else if(list_x[2] == x_1) {
                list_y[2] = y_1;
            }
        }
        {
            if(list_x[0] == x_2) {
                list_y[0] = y_2;
            }
            else if(list_x[1] == x_2) {
                list_y[1] = y_2;
            }
            else if(list_x[2] == x_2) {
                list_y[2] = y_2;
            }
        }
        {
            if(list_x[0] == x_3) {
                list_y[0] = y_3;
            }
            else if(list_x[1] == x_3) {
                list_y[1] = y_3;
            }
            else if(list_x[2] == x_3) {
                list_y[2] = y_3;
            }
        }

        /*
            for(int i = 0; i <= list_x.size(); i++) {
                std::cout << list_x[i] << " ";
            }
            std::cout << std::endl;
            for(int i = 0; i <= list_y.size(); i++) {
                std::cout << list_y[i] << " ";
            }
            std::cout << std::endl;
        */

        // y
        ex_y_1 = list_y[0];
        e_y_1 = list_y[1];
        ex_y_2 = list_y[2];

        // Le point quelconque entre les deux extrêmes est-il plus proche de l'extrême 1 ou de l'extrême 2 ?
        if(abs(e_x_1 - ex_x_1) < abs(e_x_1 - ex_x_2)) {
            // Le point est plus proche de l'extrême 1
            if(ex_y_1 > e_y_1) {
                // La droite descend
                a = (ex_y_1 - e_y_1)/(ex_x_1 - e_x_1);
            }
            else {
                // La droite monte
                a = (e_y_1 - ex_y_1)/(e_x_1 - ex_x_1);
            }
            // Paramètre 'b' des deux droites
            // b = -a * -x + y
            b_1 = a * e_x_1 - e_y_1;
            b_2 = (-a * -ex_x_2) + ex_y_2;
        }
        else {
            // Le point est plus proche de l'extrême 2
            if(ex_y_2 > e_y_1) {
                // La droite descend
                a = (ex_y_2 - e_y_1)/(ex_x_2 - e_x_1);
            }
            else {
                // La droite monte
                a = (e_y_1 - ex_y_2)/(e_x_1 - ex_x_2);
            }
            // Paramètre 'b' des deux droites
            // b = -a * -x + y
            b_1 = a * e_x_1 - ex_y_2;
            b_2 = (-a * -ex_x_1) + ex_y_1;
        }

        /*
            y_1 = y_2
            a_1 * x + b_1 = a_2 * x + b_2
            a_1 * x = a_2 * x + b_2 - b_1
            (a_1 * x) - (a_2 * x) = a_3 * x
            b_2 - b_1 = b_3
            a_3 * x = b_3
            (b_3)/(a_3) = x
            Ce qui donne, après expansion :
            (b_2 - b_1)/((a_1) - (a_2)) = x
        */
        // L'intersection des deux règles représente le paramètre 'h' de la fonction valeur absolue.
        h = (b_2 - b_1)/((a) - (-a));

        // Paramètre 'k'. Pour un 'x' de 'h', à quelle position en 'y' nous trouvons-nous ?
        // Note : ceci devrait donner le même résultat si la variable b_2 était utilisée.
        k = a * h + b_1;

        // Signe de la pente de la fonction valeur absolue
        float staging_a = abs(a);
        std::cout << staging_a;
        if(e_x_1 < h) {
            if(e_y_1 > ex_y_1) {
                // Le point quelconque est plus bas que l'extrême 1
                a = -staging_a;
            }
        }
        else {
            if(e_y_1 > ex_y_2) {
                // Le point quelconque est plus bas que l'extrême 2
                a = -staging_a;
            }
        }

        std::string f;
        f = "f(x) = " + std::to_string(a) + "|" + "x" + " - " + std::to_string(h) + "|" + " + " + std::to_string(k);
        
        return(f);
    }
    return("N/A");
}

// Trouver la Règle d'une Fonction Exponentielle
// Forme étudiée en classe : f(x) = a(c)^(bx)
std::string TRFE() {

}
