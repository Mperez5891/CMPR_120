// Tools.h

#include<string>
using namespace std;

void flush(void);
void pause(void);

int getInt( string prompt );
float getFloat( string prompt );
char getChar( string prompt );

int getNonnegativeInt( string prompt );
int getPositiveInt( string prompt );
bool getBool( string prompt );
int getBoundedInt( string prompt, int lowBound, int highBound );

int numberWidth( int number );

int larger( int A, int B );
int smaller( int A, int B );
