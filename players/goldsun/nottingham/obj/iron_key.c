inherit "obj/key";

id( strang)
{
 if ( ( strang == "key" )||( strang == type + " key")||( strang == "H_key") )
   return 1;
 return 0;
}

void reset(string arg){
 if (arg) return;
 set_type("iron");
 set_code("special_tr_key_003");
}

