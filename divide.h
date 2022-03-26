#ifndef DIVIDE
#define DIVIDE

#include <vector>
#include <string>
#include <iostream>
#include "solucion.h"
#include "problema.h"

/**
 * @brief Framework para resolver problemas de divide y venceras binarios
 * 
 */
class Framework {
 public:
  Framework();
  virtual ~Framework();
 /**
  * @brief Algoritmo general de un problema divide y vencerás.
  * 
  * @param p Problema concreto a resolver
  * @param s Solucion a devolver 
  */
  void Solve(Problem* p, Solution* s);


  /**
   * @brief Devuelve la funcion de recurrencia del algoritmo
   * 
   * @return std::string 
   */
  std::string Recurrence();


  /**
   * @brief Comprueba si el problema es lo suficientemente pequeño
   * para resolverlo
   * 
   * @param p 
   * @return true 
   * @return false 
   */
  virtual bool isSmall(Problem* p) = 0;


  /**
   * @brief Divide el problema en 2 subproblemas
   * 
   * @return std::pair<Problem*,Problem*> 
   */
  virtual std::pair<Problem*,Problem*> Divide(Problem* p) = 0;


  /**
   * @brief Resuelve una instancia lo suficientemente
   * pequeña del problema
   * 
   * @param p 
   * @param s 
   */
  virtual void SolveSmall(Problem* p, Solution* s) = 0;


  /**
   * @brief Combina la solucion de 2 subproblemas
   * 
   */
  virtual void combine(std::pair<Solution*, Solution*> subSolutions, Solution* s) = 0;


  /**
   * @brief Devuelve un string con el numero de subproblemas en el que se dividen
   * los problemas en cada iteración.
   * 
   * @return std::string 
   */
  virtual std::string getA() = 0;
  /**
   * @brief Devuelve un string con el factor de reduccion del problema
   * 
   * @return std::string 
   */
  virtual std::string getB() = 0;
  /**
   * @brief Devuelve un string con la complejidad de dividir y fusionar las soluciones.
   * 
   * @return std::string 
   */
  virtual std::string getC() = 0;
};

#endif