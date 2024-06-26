/*
* Proyecto Invernadero
* Frida Arcadia Luna
* A01711615
* 11 de junio 2024
*/

/*
* En este archivo se encuentra la clase Planta, que es la clase padre, 
* junto con 3 clases hijas, que son Fruit, Medicinales y Flores. De la clase 
* padre se heredan los atributos nombre y edad, además del método imprime_atributos, 
* que implementa polimorfismo. Cada clase hija agrega atributos y métodos propios.
*/

#ifndef PLANTA_H
#define PLANTA_H

#include <string>
#include "Abejas.h" 

//Declaración de clase Planta que es abstracta
class Planta { 

    //Declaro las variables protegidas de instancia
    protected:
    int edad; 
    std::string nombre;
    public: 
    // Atributos públicos
    
    /**
     *  Constructor por default 
     * 
     * @param
     * @return Objeto Planta
     */
    Planta(): nombre(""), edad(0){};
    /**
     *  Constructor 
     * 
     * @param nom, ed
     * @return Objeto Planta
     */ 
    Planta(std::string nom, int ed): nombre(nom), edad(ed){};
    // Métodos miembro de la clase
    virtual void imprime_atributos() = 0;  //Método abstracto que será sobreescrito
};
// Declaración clase Flores que hereda de clase Planta
class Flores:public Planta{ 

    //Declaro las variables privadas de instancia
    private: 
    std::string color;
    float litros, litros1;
    // Objeto tipo Abejas
    Abejas poliniza; 

    public: 
    /**
     *  Constructor por default 
     * 
     * @param
     * @return Objeto Flores
     */
    Flores(): Planta(), color(""), litros(0){}; 
     /**
     *  Constructor 
     * 
     * @param nom, ed, col, lit
     * @return Objeto Flores
     */ 
    Flores(std::string nom, int ed, std::string col, float lit): Planta(nom, ed), color(col), litros(lit){};
    //Métodos miembros de la clase
    void set_color(std::string);
    std::string get_color();
    void set_litros(float);
    float get_litros(int);
    void riego(int);
    Abejas get_abejas();
    void set_abejas(int);
    void set_nombre (std::string); 
    std::string get_nombre(); 
    void set_edad (int); 
    int get_edad(); 
    void imprime_atributos();

};
/**
 * Función imprime_atributos
 * Imprime los atributos de la clase, para usar polimorfismo
 * 
 * @param 
 * @return
 */
void Flores::imprime_atributos(){
    std::cout << "Name: " << nombre << std::endl;
    std::cout << "Age: " << edad << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << std::endl;
}
/**
 * setter de variable color
 * Asigna a la variable un string que recibe del Objeto
 * 
 * @param col
 * @return
 */
void Flores::set_color(std::string col){ 
    color = col;
}
/**
 * getter de variable color
 * regresa color
 * 
 * @param
 * @return color
*/
std::string Flores::get_color(){ 
    return color;
}
/**
 * setter de variable litros
 * Asigna a la variable un float que recibe del Objeto
 * 
 * @param lit
 * @return
 */
void Flores::set_litros(float lit){ 
    litros = lit;
}
/**
 * getter de variable litros
 * regresa litros
 * 
 * @param temporada
 * @return litros
*/
float Flores::get_litros(int temporada){ 
    if(temporada == 1 || temporada == 2){
        return litros;
    }
    else if(temporada == 3 || temporada == 4){
        return litros1;
    }
}
/**
 * Función riego
 * Modifica la variable litros dependiendo del input del usuario
 * 
 * @param temporada
 * @return
 */
void Flores::riego(int temporada){ 
    if (temporada == 3 || temporada == 4){
        litros1 = litros / 2;
    }
}
/**
 * Setter de variable poliniza
 * Crea un objeto con el parámetro que recibe
 * 
 * @param bees
 * @return
 */
void Flores::set_abejas(int bees){
    Abejas pol(bees);
    poliniza = pol;
}
/**
 * getter de variable poliniza
 * regresa poliniza
 * 
 * @param
 * @return poliniza
*/
Abejas Flores::get_abejas(){
    return poliniza;
}
/**
 * setter de variable nombre
 * Asigna a la variable un string que recibe del Objeto
 * 
 * @param nom
 * @return
 */
void Flores::set_nombre(std::string nom){ 
    // parametro: variable de instancia
    nombre = nom;
}
/**
 * getter de variable nombre
 * regresa nombre
 * 
 * @param
 * @return nombre
*/
std::string Flores::get_nombre(){ 
    return nombre;
}
/**
 * setter de variable edad
 * Asigna a la variable un entero que recibe del Objeto
 * 
 * @param ed
 * @return
 */
void Flores::set_edad(int ed){ 
    edad = ed;
}
/**
 * getter de variable edad
 * regresa edad
 * 
 * @param
 * @return edad
*/
int Flores::get_edad(){ 
    return edad;
}

//Declaración de clase Medicinales que hereda de clase Plantas
class Medicinales:public Planta{ 

    //Declaro las variables privadas de instancia
    private: 
    std::string uso;
    std::string origen;

    public: 
     /**
     *  Constructor por default 
     * 
     * @param
     * @return Objeto Medicinales
     */
    Medicinales(): Planta(), uso(""), origen(""){}; 
    /**
     *  Constructor 
     * 
     * @param nom, ed, ori, use
     * @return Objeto Medicinales
     */ 
    Medicinales(std::string nom, int ed, std::string ori, std::string use): Planta(nom, ed), uso(use), origen(ori){};
    //Métodos miembros de la clase
    void set_origen(std::string);
    std::string get_origen();
    void set_uso(std::string);
    std::string get_uso();
    void set_nombre (std::string); 
    std::string get_nombre(); 
    void set_edad (int); 
    int get_edad(); 
    void imprime_atributos();
};
/**
 * Función imprime_atributos
 * Imprime los atributos de la clase, para usar polimorfismo
 * 
 * @param 
 * @return
 */
void Medicinales::imprime_atributos(){
    std::cout << "Name: " << nombre << std::endl;
    std::cout << "Age: " << edad << std::endl;
    std::cout << "Origin: " << origen << std::endl;
    std::cout << "Use: " << uso << std::endl;
    std::cout << std::endl;
}
/**
 * Setter de variable origen
 * Asigna un string a la variable
 * 
 * @param ori
 * @return
 */
void Medicinales::set_origen(std::string ori){ 
    origen = ori;
}
/**
 * getter de variable origen
 * regresa origen
 * 
 * @param
 * @return origen
*/
std::string Medicinales::get_origen(){ 
    return origen;
}
/**
 * Setter de variable uso
 * Asigna un string a la variable
 * 
 * @param use
 * @return
 */
void Medicinales::set_uso(std::string use){ 
    uso = use;
}
/**
 * getter de variable uso
 * regresa uso
 * 
 * @param
 * @return uso
*/
std::string Medicinales::get_uso(){ 
    return uso;
}
/**
 * setter de variable nombre
 * Asigna a la variable un string que recibe del Objeto
 * 
 * @param nom
 * @return
 */
void Medicinales::set_nombre(std::string nom){ 
    // parametro: variable de instancia
    nombre = nom;
}
/**
 * getter de variable nombre
 * regresa nombre
 * 
 * @param
 * @return nombre
*/
std::string Medicinales::get_nombre(){ 
    return nombre;
}
/**
 * setter de variable edad
 * Asigna a la variable un entero que recibe del Objeto
 * 
 * @param ed
 * @return
 */
void Medicinales::set_edad(int ed){ 
    edad = ed;
}
/**
 * getter de variable edad
 * regresa edad
 * 
 * @param
 * @return edad
*/
int Medicinales::get_edad(){ 
    return edad;
}

//Clase Fruit
class Fruit:public Planta{ 

    //Declaro las variables privadas de instancia
    private: 
    std::string type;
    std::string time;
    int altura;

    public: 
    /**
     *  Constructor por default 
     * 
     * @param
     * @return Objeto Fruit
     */
     Fruit(): Planta(), type(""), time(""), altura(0){}; 
     /**
     *  Constructor 
     * 
     * @param nom, ed, ty, ti
     * @return Objeto Fruit
     */
     Fruit(std::string nom, int ed, std::string ty, std::string ti):Planta(nom, ed), type(ty), time(ti){};
     /**
     *  Constructor 
     * 
     * @param nom, ed, ty, ti, alt
     * @return Objeto Fruit
     */ 

     Fruit(std::string nom, int ed, std::string ty, std::string ti, int alt): Planta(nom, ed), type(ty), time(ti), altura(alt){};
     // Metodos miembro de la clase
     void set_type(std::string);
     std::string get_type();
     void set_time(std::string);
     std::string get_time();
     void set_altura(int);
     int get_altura();
     void height(int, int);
     void set_nombre (std::string); 
     std::string get_nombre(); 
     void set_edad (int); 
     int get_edad(); 
     void imprime_atributos();
};
/**
 * Función imprime_atributos
 * Imprime los atributos de la clase, para usar polimorfismo
 * 
 * @param 
 * @return
 */
void Fruit::imprime_atributos(){
    std::cout << "Name: " << nombre << std::endl;
    std::cout << "Age: " << edad << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "When it bears fruit: " << time << std::endl;
    std::cout << std::endl;
}
/**
 * Setter de variable type
 * Asigna un string a la variable
 * 
 * @param ty
 * @return
 */
void Fruit::set_type(std::string ty){ 
    type = ty;
}
/**
 * getter de variable type
 * regresa type
 * 
 * @param
 * @return type
*/
std::string Fruit::get_type(){ 
    return type;
}
/**
 * Setter de variable time
 * Asigna un string a la variable 
 * 
 * @param ti
 * @return
 */
void Fruit::set_time(std::string ti){ 
    time = ti;
}
/**
 * getter de variable time
 * regresa time
 * 
 * @param
 * @return time
*/
std::string Fruit::get_time(){ 
    return time;
}
/**
 * Setter de variable altura
 * Asigna un entero a la variable
 * 
 * @param alt
 * @return
 */
void Fruit::set_altura(int alt){ 
    altura = alt;
}
/**
 * getter de variable altura
 * regresa altura
 * 
 * @param
 * @return altura
*/
int Fruit::get_altura(){ 
    return altura;
}
/**
 * Función height
 * Modifica la variable altura dependiendo del input del usuario
 * 
 * @param pulg, years 
 * @return
 */
void Fruit::height(int pulg, int years){ 
    if (years < 20){
    altura = (years * pulg);
    
}
}
/**
 * setter de variable nombre
 * Asigna a la variable un string que recibe del Objeto
 * 
 * @param nom
 * @return
 */
void Fruit::set_nombre(std::string nom){ 
    // parametro: variable de instancia
    nombre = nom;
}
/**
 * getter de variable nombre
 * regresa nombre
 * 
 * @param
 * @return nombre
*/
std::string Fruit::get_nombre(){ 
    return nombre;
}
/**
 * setter de variable edad
 * Asigna a la variable un entero que recibe del Objeto
 * 
 * @param ed
 * @return
 */
void Fruit::set_edad(int ed){ 
    edad = ed;
}
/**
 * getter de variable edad
 * regresa edad
 * 
 * @param
 * @return edad
*/
int Fruit::get_edad(){ 
    return edad;
}
#endif // PLANTA_H
