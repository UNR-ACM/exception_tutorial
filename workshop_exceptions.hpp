/*
 *  File:           workshop_exceptions.hpp
 *  Authors:        Terence Henriod
 *                  (You, of course. This is interactive!)
 *  Last Modified:  Sometime
 *  Description:    This file defines some basic exceptions to
 *                  help learn some basics of C++ exceptions.
 */

#ifndef __WORKSHOP_EXCEPTIONS_HPP__
#define __WORKSHOP_EXCEPTIONS_HPP__

#include <cstdlib>
#include <string>
#include <exception>

class WorkshopStdExceptionWrapper : public std::exception {
 public:
    WorkshopStdExceptionWrapper(std::string pMessage) {
        mMessage = pMessage;
    }

    virtual ~WorkshopStdExceptionWrapper() throw() {
    }

    virtual const char* what() const throw() {
        return mMessage.c_str();
    }

    const std::string getMessage() const {
        return mMessage;
    }

    const std::string getDetails() {
      return mDetails;
    }

    void addDetail(std::string pDetail) {
      mDetails.append(pDetail + "\r\n");
    }

 private:
    std::string mMessage;
    std::string mDetails;
};


class UserEnteredLetterException : public WorkshopStdExceptionWrapper {
 public:
  UserEnteredLetterException(const std::string pMessage, const char pLetterChar)
    : WorkshopStdExceptionWrapper(pMessage) {
                                // <-----------   finish this constructor
  }

  const char getEnteredLetter() { // <------------   complete this method
    return 0;
  }


 private:
                                // <----------  Add appropriate member variable
};


class UserEnteredDigitException : public WorkshopStdExceptionWrapper {
 public:
  UserEnteredDigitException(const std::string pMessage, const char pLetterChar)
    : WorkshopStdExceptionWrapper(pMessage) {
                                // <-----------   finish this constructor
  }

  const int getEnteredDigit() { // <------------   complete this method
    return 0;
  }


 private:
                                // <----------  Add appropriate member variable
};

///////////////////////////////////////////////
// Now try creating your own exception!
// Try making one from scratch (no inheriance),
// then try making a derived exception!
///////////////////////////////////////////////


#endif // ifndef __WORKSHOP_EXCEPTIONS_HPP__