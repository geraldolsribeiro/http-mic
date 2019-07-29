#include <httplib.h>
#include <iostream>

using namespace std;
using namespace httplib;

void doTheMagicWithSound( const Request &req, Response &res )
{
  cout << "Beep beep beep" << endl;

  for( const auto &x : req.headers ) {
    cout << "Cabeçalho " << x.first << " = " << x.second << endl;
  }

  for( const auto &p : req.params ) {
    cout << "Parâmetro " << p.first << " = " << p.second << endl;
  }

  for( const auto &f : req.files ) {
    const auto &name = f.first;
    const auto &file = f.second;

    cout << "Name: " << name << endl;
    cout << "Filaname: " << file.filename << endl;
    cout << "Content type: " << file.content_type << endl;
    cout << "Offset: " << file.offset << endl;
    cout << "Length: " << file.length << endl;

    if( name == "snd" ) {
      ofstream snd( "audio-recebido.wav" );
      snd << req.body.substr( file.offset, file.length );
    }
  }

  auto algumaResposta = "xxx";
  res.set_content( algumaResposta, "text/plain" );
}

int main( void )
{
  Server server;
  server.Post( "/soundInput", doTheMagicWithSound );
  server.Get( "/stop", [&]( [[maybe_unused]] const Request &req, [[maybe_unused]] Response &res ) {
    server.stop();
    cout << "Fui!" << endl;
  } );

  server.listen( "localhost", 1234 );
}
