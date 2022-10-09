typedef union {
struct Nissim
{
unsigned int 
src
:16;
unsigned int 
dst
:16;
unsigned int 
checksum
:16;
unsigned int 
len
:16;
}; unsigned int array[4];
} InstanceProtocol;