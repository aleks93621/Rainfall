#include <stdlib.h>
#include <string.h>

class N
{
	private:
		int		_n;
		char	string[100];	// String qui va contenir l'annotation

	public:
		N(int n) : _n(n) {}		// Constructeur 

		void	setAnnotation(char *str)	// Fonction setAnnotation() qui va modifier string
		{
			memcpy(this->string, str, strlen(str));
			return;
		}

		int operator+(N &arg) { return (this->_n + arg._n); } // Opérateur +
		int operator-(N &arg) { return (this->_n - arg._n); } // Opérateur -

};

int main(int ac, char **av)
{
	N	*n5;
	N	*n6;
	int	addition;

	/*
		0x080485fe <+10>:	cmp    DWORD PTR [ebp+0x8],0x1
   		0x08048602 <+14>:	jg     0x8048610 <main+28> // jump if ac > 1
	*/
	if (ac <= 1)
	/*
		0x08048604 <+16>:	mov    DWORD PTR [esp],0x1
   		0x0804860b <+23>:	call   0x80484f0 <_exit@plt> // Exit(1) si ac <= 1
	*/
		exit(1);

	/*
		0x08048610 <+28>:	mov    DWORD PTR [esp],0x6c 
   		0x08048617 <+35>:	call   0x8048530 <_Znwj@plt>   /////// Class operator c++filt _Znwj
   		0x0804861c <+40>:	mov    ebx,eax				   ////// operator new(unsigned int)

   		0x0804861e <+42>:	mov    DWORD PTR [esp+0x4],0x5 //////// n5->_n = 5
  		0x08048626 <+50>:	mov    DWORD PTR [esp],ebx
   		0x08048629 <+53>:	call   0x80486f6 <_ZN1NC2Ei>   ///////// Constructor class N
		
		0x08048654 <+96>:	mov    eax,DWORD PTR [esp+0x1c]
   		0x08048658 <+100>:	mov    DWORD PTR [esp+0x14],eax ///// n5 ---> esp+0x14
	*/
	n5 = new N(5);
	/*
		0x08048632 <+62>:	mov    DWORD PTR [esp],0x6c
   		0x08048639 <+69>:	call   0x8048530 <_Znwj@plt> /////// Class operator c++filt _Znwj
   		0x0804863e <+74>:	mov    ebx,eax				 ////// operator new(unsigned int)

   		0x08048640 <+76>:	mov    DWORD PTR [esp+0x4],0x6 //////// n6->_n = 6
   		0x08048648 <+84>:	mov    DWORD PTR [esp],ebx
   		0x0804864b <+87>:	call   0x80486f6 <_ZN1NC2Ei> ///////// Constructor class N

		0x0804865c <+104>:	mov    eax,DWORD PTR [esp+0x18]
   		0x08048660 <+108>:	mov    DWORD PTR [esp+0x10],eax //// n6 ---> esp+0x10
	*/
	n6 = new N(6);
	/*
		0x08048654 <+96>:	mov    eax,DWORD PTR [esp+0x1c]
   		0x08048658 <+100>:	mov    DWORD PTR [esp+0x14],eax ///// n5 ---> esp+0x14

   		0x0804865c <+104>:	mov    eax,DWORD PTR [esp+0x18]
   		0x08048660 <+108>:	mov    DWORD PTR [esp+0x10],eax //// n6 ---> esp+0x10

   		0x08048664 <+112>:	mov    eax,DWORD PTR [ebp+0xc]	// av[0]
   		0x08048667 <+115>:	add    eax,0x4					// av[1]
   		0x0804866a <+118>:	mov    eax,DWORD PTR [eax]
   		0x0804866c <+120>:	mov    DWORD PTR [esp+0x4],eax  /////// arg1 = av[1]
   		0x08048670 <+124>:	mov    eax,DWORD PTR [esp+0x14] ////// class = n1
   		0x08048674 <+128>:	mov    DWORD PTR [esp],eax
   		0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc> //// N::setAnnotation(char*)
	*/
	n5->setAnnotation(av[1]);

	return (*n5 + *n6); 
}