/* KEY.C - This is an inherit/clone file. DO NOT COPY! */
/* 230693: Ethereal Cashimor: USERDOC added */

string type;
string code;

/* USERDOC:
general
This is the key belonging to /obj/door.c. This key can also be made using a
macro in the door.h file. Generally defined functions:
query_value, query_name.
*/

short()
{
 return "An " + type + " key";
}

/* USERDOC:
set_key_data
Format: set_key_data(s)
Example: set_key_data("purple jen")
See also: query_type, query_code.
This function sets the data of the key. The data consists of two strings,
divided by a space.
string 1 = code of the lock which the key will fit into
string 2 = code of the key itself
If you use 'zap' as the code of the key (string 2) then the key will 
fit into any lock.  Do not use this code often.
*/
set_key_data(str) {
  if ( sscanf(str, "%s %s", type, code) == 2) 
    return 1;
  return 2;
}
long()
{
 write("This a " + type + " key.\n"+
       "It looks very valuable, and you start to wonder\n"+
       "where it fits?\n"); 
}

id( strang)
{
 if ( ( strang == "key" )||( strang == type + " key")||( strang == "H_key") )
   return 1;
 return 0;
}

get()
{
  return 1;
}

query_value() {
 return 20;
}

/* USERDOC:
query_type
Format: s=query_type()
See also: set_key_data, set_type.
This function returns the kind of lock the key fits into.
*/
query_type() { 
  return type; 
}

/* USERDOC:
query_code
Format: s=query_code()
See also: set_key_data, set_code.
This function returns the code of the lock this key opens.
*/
query_code() { 
  return code; 
}

/* USERDOC:
set_type
Format: set_type(s)
Example: set_type("purple")
See also: set_key_data, query_type.
This function sets the kind of lock this key will fit into.
*/
set_type(str) {
  type = str;
}

/* USERDOC:
set_code
Format: set_code(s)
Example: set_code("jen")
See also: set_key_data, query_code.
This function sets the code of this key. Note that code 'zap' can open all
doors, but please don't use 'zap' often, otherwise doors will become useless.
*/
set_code(str) { 
  code = str; 
}

init()
{
}

reset( arg)
{
 if(arg)
   return;
 type = 0;
 code = 0;
}

query_name() { 
  return "key"; 
}
