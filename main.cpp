#include <iostream>

/* Functions prototypes */
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main(int argc, char** argv){
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;

    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;

    // Test 3: Concaténation
    char salutation[100] = "Foot";
    ConcatenerChaines(salutation, "Ball");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;

    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }

    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " << CompterOccurrences(message, 'o') << std::endl;

    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;

    // Test 7: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "7. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;

    // Test 8: Initialisation mémoire
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "8. Initialisation mémoire: '" << zone3 << "'" << std::endl;

    // Test 9: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "9. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " << resultat_comparaison << std::endl;

    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;

    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    return 0;
}

// Determines and returns the length of a string
// e.g LongueurChaine("Hello") returns 5

size_t LongueurChaine(const char* chaine){
    const char* debut = chaine;
    while (*chaine != '\0') {
        chaine++;
    }
    return chaine - debut;
}

// Copies the value of one string(source) to another (destination)
// e.g CopierChaine(cpy, "Hello"), here cpy takes the value "Hello"

void CopierChaine(char* destination, const char* source){
    while (*source != '\0') {
        *destination = *source;
        source++, destination++;
    }
    // Terminating the copied string with '\0'
    *destination = '\0';
}


// Catenates(Joins) one string(source) at the end of another(destination)
// e.g ConcateneChaines("Foot", "Ball"), joins "Ball" to "Foot"

void ConcatenerChaines(char* destination, const char* source){
    // Repeating until the original end of destination
    do {
        if(*destination == '\0'){
            while (*source != '\0') {
                *destination = *source;
                source++, destination++;
            }
            break;
        }
        destination++;
    }while (true); 

    *destination = '\0';
}

//  determines and returns the position of a character in a given string if found
// e.g TrouverCaractere("Hello", 'o') returns 4 and TrouverCaractere("Hello", 'j') returns a nullptr 

char* TrouverCaractere(const char* chaine, char caractere){
    while (*chaine != '\0') {
        if (*chaine == caractere) return  (char*)chaine; 
        chaine++;
    }
    return nullptr;
}

// Counts and returns the numbers of times a given character appears in a string
// e.g CompterOccurrences("Bonjour", 'o') returns 2

size_t CompterOccurrences(const char* chaine, char caractere){
    size_t i = 0;
    while (*chaine != '\0'){
        if(*chaine == caractere) i++;
        chaine++;
    }
    return i;
}

// Extracts a portion from a given string depending on a bound
// e.g ExtraireSousChaine(str, "Hello", 0, 1) generates "He" from "Hello"

void ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur){
    int i;
    if (source[debut] == NULL) *destination = NULL;

    for(i=0; i < longueur - 1; i++){
        destination[i] = source[debut + i];
        if(source[debut + i] == '\0') break;
    }
    destination[i] = '\0';
}

// Copies directly the memory of one string(source) to another (destination)
// e.g CopierMemoire(zone2, zone1, 10)

void CopierMemoire(void* destination, const void* source, size_t taille){
    // conversion of void* to unsigned char* using static_cast (explicit cast)
    unsigned char* dest = static_cast <unsigned char*> (destination);
    unsigned const char* orig = static_cast <unsigned const char*> (source);

    for(int i=0; i <= taille - 1; i++){
        *dest = *orig;
        dest++, orig++;
    }
}

// creates and allocates a new space in memory for a string 
// e.g InitialiserMemoire(zone3, 'X', 5)

void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille){
    unsigned char* modif_zone = static_cast <unsigned char*> (zone);

    for(int i=0; i <= taille - 1; i++){
        *modif_zone = valeur;
        modif_zone++;
    }
}

// Divides a string into several substring according to a limiter without affecting the original string and returns the number of substrings generated
// e.g DiviserChaine("Youmbi,Bovan", ',', result, 10) returns 2 and give rise to the substrings "Youmbi" and "Bovan"

size_t DiviserChaine(const char* chaine, char separateur, char resultat[][100], size_t max_resultats){
    char sous_chaine[max_resultats];
    size_t compteur_resultats = 0, index_courant = 0;

    while(*chaine != '\0'){
        if(*chaine == separateur || *chaine == '\0'){ 
            CopierChaine(resultat[compteur_resultats], sous_chaine);
            compteur_resultats++;
            index_courant = 0;
        }
        else{
            sous_chaine[index_courant] = *chaine;
            index_courant++;
        }
        chaine ++;
    }
    return compteur_resultats;
}

// Compares two strings and verifies who comes first in the alphabetical order and returns
// 0 if the strings are the same
// >0 if chaine1 > chaine2 and
// <0 if chaine1 < chaine2
// e.g ComparerChaines("apple", "banana") returns 7 which is >0


int ComparerChaines(const char* chaine1, const char* chaine2){
    while (*chaine1 != '\0' && *chaine2 != '\0'){
        if(*chaine1 != *chaine2) return chaine1 - chaine2;
    }
    return 0;
}

// Converts all characters of a string to lowercase characters 
// e.g ConvertirMinuscules("Hello") gives "hello"

void ConvertirMinuscules(char* chaine){
    while(*chaine != '\0') {
        if(*chaine >= 65 && *chaine <= 91){
            *chaine += 32;
        }
        chaine++;
    }
}

// Checks if all characters of a string are numerical
// e.g EstChaineNumerique("12345") returns true and EstChaineNumerique("12a45") returns false

bool EstChaineNumerique(const char* chaine){
    if(*chaine == '-') chaine++;

    while(*chaine != '\0'){
        if(*chaine < 48 || *chaine > 57) return 0;
        chaine++;
    }
    return 1;
}