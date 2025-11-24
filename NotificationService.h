#pragma once
#include <iostream>
#include <string>
#include "Notification_Service.h"

Class NotificationService {
public:
  virtual ~NotificationService() = default;
  virtual bool connectToProvider(const std::string& provider) = 0;
  virtual bool send(const std::string& recipient, const std::string& message) = 0
};
