#ifndef COMMON_H
#define COMMON_H


#define SAFE_DELETE(p) do{if(p){delete(p);(p)=nullptr;}}while(false)
#define SAFE_DELETE_ARRAY(arr) do{if(arr){delete[](arr);(arr)=nullptr;}}while(false)


#endif
