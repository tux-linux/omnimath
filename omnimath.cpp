#include "omnimath.h"

// Options générales
#define TROUVER_REGLE_FONCTION 1

// Options "Trouver la règle d'une fonction"
#define F_R_VALEUR_ABSOLUE 1
#define F_R_EXPO 2
#define F_R_LOG 3

// Options "Valeur absolue : options pour trouver la règle"
#define F_R_VALEUR_ABSOLUE_POINT_SOMMET 1
#define F_R_VALEUR_ABSOLUE_2POINTS_ORD_POINT 2
#define F_R_VALEUR_ABSOLUE_3POINTS 3

// Options "Exponentielle : options pour trouver la règle"
#define F_R_EXPO_ORD_POINT 1
#define F_R_EXPO_2POINTS 2

// Options "Logarithmique : options pour trouver la règle"
#define F_R_LOG_B_C_POINT 1
#define F_R_LOG_A_C_POINT 2
#define F_R_LOG_A_2POINTS 3

int main() {
    if(std::getenv("DEBUG") != NULL) {
        debug = true;
    };
    std::list<std::string> options = { "Trouver la règle d'une fonction" };
    int option = imprimerOptions(options);
    if(option == TROUVER_REGLE_FONCTION) {
        options = { "Valeur absolue ", "Exponentielle", "Logarithmique" };
        option = imprimerOptions(options);
        if(option == F_R_VALEUR_ABSOLUE) {
            std::string fn = TRFVA();
            std::cout << std::endl << "=> " << fn << std::endl;
        }
        else if(option == F_R_EXPO) {
            std::string fn = TRFE();
            std::cout << std::endl << "=> " << fn << std::endl;
        }
        else if(option == F_R_LOG) {
            std::string fn = TRFL();
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

        if(debug) {
            std::cout << std::endl;
            log("Liste des x:");
            for(int i = 0; i <= list_x.size(); i++) {
                    std::cout << list_x[i] << ", ";
            }
            std::cout << std::endl;
            log("Liste des y:");
            for(int i = 0; i <= list_y.size(); i++) {
                std::cout << list_y[i] << ", ";
            }
            std::cout << std::endl << std::endl;
        }

        // y
        ex_y_1 = list_y[0];
        e_y_1 = list_y[1];
        ex_y_2 = list_y[2];

        log("Extrême 1: (" + std::to_string(ex_x_1) + ", " + std::to_string(ex_y_1) + ")");
        log("Point quelconque: (" + std::to_string(e_x_1) + ", " + std::to_string(e_y_1) + ")");
        log("Extrême 2: (" + std::to_string(ex_x_2) + ", " + std::to_string(ex_y_2) + ")");

        // Le point quelconque entre les deux extrêmes est-il plus proche de l'extrême 1 ou de l'extrême 2 ?
        if(abs(e_x_1 - ex_x_1) < abs(e_x_1 - ex_x_2)) {
            log("Le point quelconque est plus proche de l'extrême 1");
            if(ex_y_1 > e_y_1) {
                log("La droite descend");
                a = (ex_y_1 - e_y_1)/(ex_x_1 - e_x_1);
            }
            else {
                log("La droite monte");
                a = (e_y_1 - ex_y_1)/(e_x_1 - ex_x_1);
            }
            // Paramètre 'b' des deux droites
            b_1 = -(a * e_x_1 - e_y_1);
            b_2 = (-a * -ex_x_2) + ex_y_2;
        }
        else {
            // Le point est plus proche de l'extrême 2
            log("Le point quelconque est plus proche de l'extrême 2");
            if(ex_y_2 > e_y_1) {
                log("La droite descend");
                a = (ex_y_2 - e_y_1)/(ex_x_2 - e_x_1);
            }
            else {
                log("La droite monte");
                a = (e_y_1 - ex_y_2)/(e_x_1 - ex_x_2);
            }
            // Paramètre 'b' des deux droites
            b_1 = -(a * e_x_1 - ex_y_2);
            b_2 = (-a * -ex_x_1) + ex_y_1;
        }
        log("a préliminaire est " + std::to_string(a));
        log("b_1 est " + std::to_string(b_1) + " et b_2 est " + std::to_string(b_2));

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
        log("h est " + std::to_string(h));

        // Paramètre 'k'. Pour un 'x' de 'h', à quelle position en 'y' nous trouvons-nous ?
        // Note : ceci devrait donner le même résultat si la variable b_2 était utilisée.
        k = a * h + b_1;
        log("k est " + std::to_string(k));

        // Signe de la pente de la fonction valeur absolue
        float staging_a = abs(a);
        /*
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
        */

        if(k > ex_y_1) {
            a = -staging_a;
        }
        else {
            a = staging_a;
        }
        log("a final est " + std::to_string(a));

        std::string f;
        f = "f(x) = " + std::to_string(a) + "|" + "x" + " - " + std::to_string(h) + "|" + " + " + std::to_string(k);
        
        return(f);
    }
    return("N/A");
}

// Trouver la Règle d'une Fonction Exponentielle
// Forme étudiée en classe : f(x) = a(c)^(bx)
std::string TRFE() {
    std::list<std::string> options = { "À partir de l'ordonnée à l'origine et d'un point quelconque", "À partir de deux points quelconques" };
    int option = imprimerOptions(options);
    if(option == F_R_EXPO_ORD_POINT) {
        float ord_x;
        float ord_y;
        float x;
        float y;
        float a;
        float c;

        std::cout << "Ordonnée à l'origine (x): "; std::cin >> ord_x;
        std::cout << "Ordonnée à l'origine (y): "; std::cin >> ord_y;
        std::cout << "Point quelconque (x): "; std::cin >> x;
        std::cout << "Point quelconque (y): "; std::cin >> y;

        // Trouver 'a'
        a = ord_y;
        log("a est " + std::to_string(a));

        // Trouver 'c'
        /*
            y = a(c)^x
            y/a = (c)^x
            (y/a)^(1/x) = c
        */
        c = pow((y/a), (1/x));
        log("c est " + std::to_string(c));

        std::string f;
        f = "f(x) = " + std::to_string(a) + "(" + std::to_string(c) + ")^x";
        
        return(f);
    }
    else if(option == F_R_EXPO_2POINTS) {
        float x_1;
        float y_1;
        float x_2;
        float y_2;
        float a;
        float c;

        std::cout << "Point 1 quelconque (x): "; std::cin >> x_1;
        std::cout << "Point 1 quelconque (y): "; std::cin >> y_1;
        std::cout << "Point 2 quelconque (x): "; std::cin >> x_2;
        std::cout << "Point 2 quelconque (y): "; std::cin >> y_2;

        /*
            y1 = a(c)^x
            y2 = a(c)^x

            y_1 = a(c)^x_1
            y_2 = a(c)^x_2

            (y_1)/((c)^x_1) = a
            (y_2)/((c)^x_2) = a
            (y_1)/((c)^x_1) = (y_2)/((c)^x_2)

            ! NE MARCHE PAS !
            (y_1)*(x_2)*((c)^x_1) = (y_2)*(x_1)*((c)^x_2)
            (y_1)*(x_2) = ((y_2)*(x_1)*((c)^x_1))/((c)^x_2)
            (y_1)*(x_2) = ((y_2)*(x_1)*((c)^(x_1-x_2)))
            (((y_1)*(x_2))/((y_2)*(x_1)))^(1/(x_1-x_2)) = (c)^(x_1-x_2) = c
            ! NE MARCHE PAS !

            // MARCHE
            ((c)^x_1)/((c)^x_2) = (y_2)/(y_1)
            (c)^(x_1-x_2) = (y_2)/(y_1)
        */

        // Trouver 'c'
        c = pow((y_1/y_2), (1/(x_1-x_2)));
        log("c est " + std::to_string(c));

        // Trouver 'a'
        /*
            y_1 = a(c)^x_1
            y_1/((c)^x_1) = a
        */
        a = y_1/(pow(c, x_1));
        log("a est " + std::to_string(a));

        std::string f;
        f = "f(x) = " + std::to_string(a) + "(" + std::to_string(c) + ")^x";

       return(f);
    }
}

// Trouver la Règle d'une Fonction Logarithmique
std::string TRFL() {
    std::list<std::string> options = { "À partir des paramètres 'b', 'c' et un point", "À partir des paramètres 'a', 'c' et un point", "À partir du paramètre 'a' et deux points" };
    int option = imprimerOptions(options);
    if(option == F_R_LOG_B_C_POINT) {
        float x;
        float y;
        float a;
        float b;
        float c;

        std::cout << "Point 1 quelconque (x): "; std::cin >> x;
        std::cout << "Point 1 quelconque (y): "; std::cin >> y;
        std::cout << "Paramètre 'b': "; std::cin >> b;
        std::cout << "Paramètre 'c': "; std::cin >> c;
        
        // Trouver 'a'
        /*
            y = a((log10(b(x)))/(log10(c)))
            y/((log10(b(x)))/(log10(c))) = a
        */
        a = y/((log10(b*x))/(log10(c)));
        log("a est " + std::to_string(a));

        std::string f;
        f = "f(x) = " + std::to_string(a) + " log10(" + std::to_string(b) + "(x))/log10(" + std::to_string(c) + ")";

        return(f);
    }
    else if(option == F_R_LOG_A_C_POINT) {
        float x;
        float y;
        float a;
        float b;
        float c;

        std::cout << "Point 1 quelconque (x): "; std::cin >> x;
        std::cout << "Point 1 quelconque (y): "; std::cin >> y;
        std::cout << "Paramètre 'a': "; std::cin >> a;
        std::cout << "Paramètre 'c': "; std::cin >> c;

        // Trouver 'b'
        /*
            y = a((log10(b(x)))/(log10(c)))
            y/a = (log10(b(x)))/(log10(c))
            c^(y/a) = b(x)
            (c^(y/a))/(x) = b
        */
        b = (pow(c, y/a))/x;
        log("b est " + std::to_string(b));

        std::string f;
        f = "f(x) = " + std::to_string(a) + " log10(" + std::to_string(b) + "(x))/log10(" + std::to_string(c) + ")";

        return(f);
    }
    else if(option == F_R_LOG_A_2POINTS) {
        float x_1;
        float y_1;
        float x_2;
        float y_2;
        float a;
        float b;
        float c;

        std::cout << "Point 1 quelconque (x): "; std::cin >> x_1;
        std::cout << "Point 1 quelconque (y): "; std::cin >> y_1;
        std::cout << "Point 2 quelconque (x): "; std::cin >> x_2;
        std::cout << "Point 2 quelconque (y): "; std::cin >> y_2;
        std::cout << "Paramètre 'a': "; std::cin >> a;

        // Trouver 'c'
        /*
            y = a((log10(b(x)))/(log10(c)))

            y_1 = a((log10(b(x_1)))/(log10(c)))
            y_2 = a((log10(b(x_2)))/(log10(c)))

            y_1/a = (log10(b(x_1)))/(log10(c))
            y_2/a = (log10(b(x_2)))/(log10(c))

            c^(y_1/a) = b(x_1)
            c^(y_2/a) = b(x_2)

            c^(y_1/a)/(x_1) = b
            c^(y_2/a)/(x_2) = b

            c^(y_1/a)/(x_1) = c^(y_2/a)/(x_2)
            (x_2)/(x_1) = c^(y_2/a)/c^(y_1/a)
            (x_2)/(x_1) = c^((y_2/a)-(y_1/a))
            ((x_2)/(x_1))^(1/((y_2/a)-(y_1/a))) = c
        */
        c = pow((x_2/x_1), 1/((y_2/a)-(y_1/a)));
        log("c est " + std::to_string(c));

        // Trouver 'b'
        b = pow(c, y_1/a)/x_1;
        log("b est " + std::to_string(b));

        std::string f;
        f = "f(x) = " + std::to_string(a) + " log10(" + std::to_string(b) + "(x))/log10(" + std::to_string(c) + ")";

        return(f);
    }
}

void log(std::string message) {
    if(debug) {
        std::cout << message << std::endl;
    }
}
