inherit "/obj/weapon";
string *type,this_type;


int query_goldsun_special(){ return 1; }

void reset(int arg){

  ::reset(arg);

 if (arg) return;
   
 type=({"copper","steel","wooden","stone","golden","silver","platinum",
        "metal","magic","bloody","bone","water","air","red","black"});
 set_value(100);
 set_weight(1);
 set_class(1);
 }

void set_type(int i){
 this_type=type[i];
}

string query_type(){
  return this_type;
}


