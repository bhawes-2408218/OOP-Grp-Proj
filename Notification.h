#pragma once
#include <iostream>
#include <string>
#include "Notification.h"

Class Notification { 
protected:
  int notifID;
  std::string patientContact;
  std::string message;
  std::string type; //SMS or Email
  
public:
  Notification() = default;
  Notification(int id, const std::string& contact, const std::string& msg, const std::string& type)
      : notifID(id), patientContact(contact), message(msg), type(type) {}
  virtual ~Notification() = default;

  virtual void sendNotif() = 0;
  virtual std::string formatMessage() = 0;

  int getID() const { return notifID; }
  std::string getContact() const { return patientContact; }
  std::string getType() const { return type; }
};
  
