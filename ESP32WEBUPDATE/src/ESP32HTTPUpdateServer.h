#ifndef __HTTP_UPDATE_SERVER_H
#define __HTTP_UPDATE_SERVER_H

class N_ESP32WEBSERVER;

class ESP32HTTPUpdateServer
{
  private:
    bool _serial_output;
    N_ESP32WEBSERVER *_server;
    static const char *_serverIndex;
    static const char *_failedResponse;
    static const char *_successResponse;
    char * _username;
    char * _password;
    bool _authenticated;
  public:
    ESP32HTTPUpdateServer(bool serial_debug=false);

    void setup(N_ESP32WEBSERVER *server)
    {
      setup(server, NULL, NULL);
    }

    void setup(N_ESP32WEBSERVER *server, const char * path)
    {
      setup(server, path, NULL, NULL);
    }

    void setup(N_ESP32WEBSERVER *server, const char * username, const char * password)
    {
      setup(server, "/update", username, password);
    }

    void setup(N_ESP32WEBSERVER *server, const char * path, const char * username, const char * password);
};


#endif
