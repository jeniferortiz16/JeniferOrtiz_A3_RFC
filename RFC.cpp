/******************************************************************************
Lenuguaje de programacion I
RFC
*******************************************************************************/
#include <iostream>
#include <string>

// funcion para obtener la primera vocal interna de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) 
{
    for (size_t i = 1; i < str.length(); ++i)  {
        char c = str[i];
        if (c == 'A' || c == 'E' || c =='I' || c == 'O'|| c == 'U')
        return c;
    } 
    return 'X'; // Si no se encuentra ninguna vocal interna se usa la x
}

//Funcion principal para calculra el RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento)
{
    std::string rfc;
    
     // Se obtiene la letra inicial y la primera vocal del apellido apellidoPaterno
     char letraInicial = apellidoPaterno[0];
     char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
     
     // Se obtiene la inicial del apellido materno o se unsa una X si no tiene
     char inicialApellidoMaterno = (!apellidoMaterno.empty()) ?
     apellidoMaterno[0] : 'X';
     
     // Se obtiene la inicial del primer nombre o se usa una X si no tiene
     char inicialNombre = nombre[0];
     
     //Se obtiene los dos ultimos digitos del año de nacimiento
     std::string anio = fechaNacimiento.substr(8, 2);
     
     // Se obtiene el mes y el dia de macimiento
     std::string mes = fechaNacimiento.substr(3, 2);
     std::string dia = fechaNacimiento.substr(0, 2);
     
     // Se contruye el rfc
     rfc = letraInicial;
     rfc += primeraVocalInterna;
     rfc += inicialApellidoMaterno;
     rfc += inicialNombre;
     rfc += anio;
     rfc += mes;
     rfc += dia;
     return rfc;
}     

//Verificacion de palabras
bool ValidarRFC(std::string rfc) {
    if (rfc.substr (0, 4) == "PENE" || rfc.substr (0, 4) == "CACA" || rfc.substr (0, 4) == "BUEI" || rfc.substr (0, 4) == "RUIN" || rfc.substr (0, 4) == "QULO" || rfc.substr (0, 4) == "PUTA" || rfc.substr (0, 4) == "PEDO" || rfc.substr (0, 4) == "MULA" || rfc.substr (0, 4) == "MION" || rfc.substr (0, 4) == "MEAS" || rfc.substr (0, 4) == "MAMO" || rfc.substr (0, 4) == "KULO" || rfc.substr (0, 4) == "KOJO" || rfc.substr (0, 4) == "KAGO" || rfc.substr (0, 4) == "KACO" || rfc.substr (0, 4) == "JOTO" || rfc.substr (0, 4) == "FETO" || rfc.substr (0, 4) == "COJO" || rfc.substr (0, 4) == "COJE" || rfc.substr (0, 4) == "COGE" || rfc.substr (0, 4) == "CAGA" || rfc.substr (0, 4) == "CAKA" || rfc.substr(0, 4) == "COJA" || rfc.substr(0, 4) == "COJI" || rfc.substr(0, 4) == "CULO" || rfc.substr(0, 4) == "GUEY" || rfc.substr(0, 4) == "MAME" || rfc.substr(0, 4) == "KAKA" || rfc.substr(0, 4) == "KAGA" || rfc.substr(0, 4) == "MOCO" || rfc.substr(0, 4) == "RATA" || rfc.substr(0, 4) == "PUTO" || rfc.substr(0, 4) == "PEDA" ) {
    return false;
}
return true;

}
int main()
{
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    
    std::cout << "Ingrese su nombre (letras mayusculas): ";
    std::getline (std::cin, nombre);
    
    std::cout << "Ingrese su apellido paterno (letras mayusculas): ";
    std::getline (std::cin, apellidoPaterno);
    
    std::cout << "Ingrese su apellido materno (letras mayusculas) si no tiene pulse enter: ";
    std::getline (std::cin, apellidoMaterno);
    
    std::cout << "Ingrese la fecha de nacimiento (DD-MM-YYYY): ";
    std::getline (std::cin, fechaNacimiento);
    
    std::string rfc = calcularRFC(nombre, apellidoPaterno,apellidoMaterno, fechaNacimiento);
    if (!ValidarRFC(rfc)) {
        rfc[3] = 'X';
    }
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}
    
    







