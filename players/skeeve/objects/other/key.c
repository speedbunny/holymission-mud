string type;
string code;

reset( arg) {
 if(!arg) {
   type = 0;
   code = 0;
  } else {
    if (!environment(environment(this_object())))
       destruct(this_object());
} }

init () {}

get() { return 1; }

short() { return "A " + type + " key"; }

long() { write("This is a " + type + " key, wonder where it fits?\n");}

id(str){ return (str=="key")||(str==type+" key");}

query_weight() { return 1; }
query_name()  { return "key"; }

query_type() { return type; }
query_code() { return code; }

set_type(atype) { type = atype; }
set_code(acode) { code = acode; }
set_data(atype,acode) { type = atype; code =acode; }
