inherit "obj/key";

string short(){ return "An orion key"; }
id( strang)
{
 if ( ( strang == "key" )||( strang == type + " key")||( strang == "H_key")||
      (	strang == "special_tr_key_001") )
   return 1;
 return 0;
}

void reset(string arg){
 if (arg) return;
 set_type("orion");
 set_code("no_code");
}


