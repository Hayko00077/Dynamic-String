//dest-i stringin kpcnum e str-i stringy:


#include <stdlib.h>
#include <string.h>
char* dstrcat(char* dest,const char* str){
	dest = (char*)realloc(dest, strlen(dest) + strlen(str) + 1);
	dest[strlen(dest) - 1] = '\0';
	int i = 0;
	while(dest[i]) {
		++i;
	}
	while(*str){
		dest[i] = *str++;
		++i;
	}
	dest[i] = '\0';
	return dest;

}


//dest-i stringin kpcnum e str-i stringy mutqagrac tvi chapov:


#include <stdlib.h>
#include <string.h>
#include <stddef.h>
char* dstrncat(char* dest,const char* str,size_t n){
         int i = strlen(dest) - 1;
         dest = (char*)realloc(dest, i + strlen(str) + 1);
//         dest[strlen(dest) - 1] = '\0';
         while(*str && n != 0){
                 dest[i] = *str++;
                 ++i;
		n--;
         }

         dest[i] = '\0';
         return dest;

}


//dest-i mej copy e anum str-i parunakutyuny:


#include <stdlib.h>
#include <string.h>

char* dstrcpy(char* dest,const char* str){
	int res = strlen(str);
	dest = (char*)realloc(dest,res * sizeof(char));
	int i = 0;
	for(i = 0; i < res;i++){
		dest[i] = str[i];
	}
	dest[i] = '\0';
	return dest;
}


//dest-i mej copy e anum str-i parunakutyuny mutqagrac tvi chapov:


#include <stdlib.h>
#include <string.h>
#include <stddef.h>
char* dstrncpy(char* dest,const char* str,size_t n){
        int res = strlen(str);
 	 dest = (char*)realloc(dest, sizeof(char*) * res);
	 for(int i = 0; i < n; i++){
		dest[i] = str[i];
	 }
	dest[n] = '\0';
         return dest;
}


// hamematutyun e katarum stringneri mej:


#include <stdlib.h>
#include <string.h>
#include <stddef.h>
   int dstrcmp(const char* dest,const char* str){
	while(*dest != '\0' && *str != '\0'){
		if(*dest > *str){
			return 1;
		}else if(*dest < *str){
			return -1;
		}else{
			dest++;
			str++;
		}
	}

	if(*dest == '\0' && *str == '\0'){
		return 0;
	}
	if(*dest == '\0'){
		return -1;
	}
	if(*str == '\0'){
		return 1;
	}

}


//hamematutyun e katarum mutqagrac tvi chapov:


#include <stdlib.h>
#include <string.h>
#include <stddef.h>
   int dstrncmp(const char* dest,const char* str,size_t n){

	while(*dest != '\0' && *str != '\0',n > 0){
		if(*dest > *str){
			return 1;
		}else if(*dest < *str){
			return -1;
		}else{
			dest++;
			str++;
			n--;
		}
	}

	if(n == 0){
		return 0;
	}
	if(*dest == '\0'){
		return -1;
	}
	if(*str == '\0'){
		return 1;
	}

}


//hashvum e stringi erkarutyuny:


#include <stdlib.h>
#include <string.h>
#include <stddef.h>

size_t dstrlen(const char* dest){
		int lenght = 0;
		while(*dest != '\0'){
				lenght++;
				dest++;
		}
		return lenght;
}


//sksum e tpel mutqagrac taric sksac (araji handipac):


#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char* dstrchr(const char* dest,int n){
		while(*dest != '\0'){
				if(*dest == (char)n){
						return (char*)dest;
				}
				dest++;
		}
		return NULL;
}



//sksum e tpel  mutqagrac taric sksac(verj handipac):


#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char* dstrrchr(const char* dest,int n){
		while(*dest != '\0'){
			dest++;
		}
		while(*dest != (char)n){
				dest--;
				if(*dest == (char)n){
						return (char*)dest;
				}
		}
		return NULL;
}


// petq e gtni iren hamarjeq bary e tpi baric sksac:


#include <stdlib.h>
#include <stddef.h>
#include <string.h>


/*char* dstrstr(const char* dest,const char* str){
	char* tmp = (char*)str;
	int count = 0;
	char* start = (char*)dest;
	while(*dest != '\0' && *str != '\0'){
			if(*dest == *str){
					dest++;
					str++;
					count++;
			}else if(*dest != *str){
					dest = start + 1;
					str = tmp;
					count = 0;
			}
	}
	return (char*)dest - count;
}
*/

/*if (*str == '\0') {
        return 0;
    }
    int index = 0;
    while (*dest != '\0') {
        char* start = (char*)dest;
        char* end = (char*)str;
        while (*dest != '\0' && end != '\0' && *dest == *end) {
            dest++;
            end++;
        }
        if (*end == '\0') {
            return index;
        }
        dest = start + 1;
		end = str;
        index++;
    }
}
*/
int dstrncmp(const char*,const char*,size_t);
size_t dstrlen(const char*);
char* dstrstr(const char* dest,const char* str){
		while(*dest){
			if(dstrncmp(dest,str,dstrlen(str)) == 0){
				return dest;
			}else{
				++dest;
			}
		}
		return NULL;
}

