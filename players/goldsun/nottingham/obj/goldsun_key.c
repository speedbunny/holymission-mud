inherit "obj/key";

reset(arg){
 if (arg) return;
 set_type("crystal");
 set_code("30041975");
}

query_auto_load(){ return "/players/goldsun/nottingham/obj/goldsun_key:"; }

prevent_insert(){ return 1; }

drop(){
 return 1;
}

