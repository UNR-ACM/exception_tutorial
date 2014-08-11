/*
 *  File:     exceptions_workshop_driver.cpp
 *  Authors:    Terence Henriod
 *          (You, of course. This is interactive!)
 *  Last Modified:  Sometime
 *  Description:  This file is the driver program to facilitate learning
 *          the basics of exceptions in C++.
 */

#include <cstdio>
#include <iostream>
#include <climits>
#include <exception> // <--- This one is important!
#include "workshop_exceptions.hpp"

const int ENOUGH_BYTES_TO_MAKE_ALLOCATION_FAIL = INT_MAX;

void warmUp();

void helloExceptions();

void catchDifferentExceptionsByInput();

void customExceptionThrower();

char getInputFromUser();


/*==============================================================================
 *
 *      MAIN FUNCTION
 *
 *==============================================================================
 */

int main(int argc, char* argv[]) {
  puts("===============================================================\n");
  puts("             UNR ACM EXCEPTION WORKSHOP                        ");
  puts("\n===============================================================\n");

  puts("A little warmup...");
  puts("===============================================================\n");
  warmUp();
  puts("\n===============================================================\n");

  // puts("Executing the \"Hello World\" of exceptions...");
  // puts("===============================================================\n");
  // helloExceptions();
  // puts("\n===============================================================\n");

  // puts("Exercising the ability to catch different exception types...");
  // puts("===============================================================\n");
  // catchDifferentExceptionsByInput();
  // puts("\n===============================================================\n");

  // try {
  //  puts("Trying things out with my own exception...");
  //  puts("===============================================================\n");
  //  customExceptionThrower();
  //  puts("\n===============================================================\n");
  // } catch () {
      // it's up to you what you do with the exception!
      // you could print it's message, you could do something unrelated,
      // or you could even re-throw it or another exception!
  // }

  return 0;
}


void warmUp() {
  // Normally, program crashes. Uncomment the lines to see how catching
  // exceptions lets the program continue and handle failure gracefully.
  // Uncomment the code to see how we can handle errors more gracefully.

  // try {
    new double [ENOUGH_BYTES_TO_MAKE_ALLOCATION_FAIL];
  // } catch (std::exception& e) {
  //   std::cout << "Exception Message: " << e.what()
  //     << std::endl << std::endl;
  //   std::cout << "Memory allocation failed, we can't use that variable."
  //     << std::endl << std::endl;
  // }

  puts("If an exception isn't caught, we won't see this text and the");
  puts("program will crash.");
  puts("By catching the exception, we can gracefully report the error,");
  puts("or take appropriate action.");
}

void helloExceptions() {
  std::cout << "Throwing and catching an STL exception:" << std::endl;

  std::cout << "Throwing and catching our own exception:" << std::endl;
    // Hint: it's a good idea to create the exception and add details
    //       before throwing it
}

void catchDifferentExceptionsByInput() {
  char userInput;

  try {
    userInput = getInputFromUser();

    if (isalpha(userInput)) {

        // <-----------------  throw an appropriate exception from here

    } else if (isdigit(userInput)) {

        // <-----------------  throw an appropriate exception from here

    } else {

      throw WorkshopStdExceptionWrapper(
        "Somehow the user entered neither a letter, nor a digit."
      );

    }

  } catch(WorkshopStdExceptionWrapper& exception) {

    std::cout << exception.getMessage() << std::endl;

  } catch (UserEnteredLetterException& exception) {

      // <-------- take appropriate action here (maybe state some info)

  } catch (UserEnteredDigitException& exception) {

      // <-------- take appropriate action here (maybe state some info)

  }

}

void customExceptionThrower() {
  // write a function that will throw an exception, but not catch it
  // instead, catch the exception in the main function.
}


char getInputFromUser() {
  char userInput = '$';

  while (!isdigit(userInput) && !isalpha(userInput)) {
    std::cout << "Please enter either a letter or a number: ";
    std::cin >> userInput;
  }

  return userInput;
}
