inherit "obj/key";

reset(arg){
 if (arg) return;
 set_type("sunny");
 set_code("zap");
}

query_auto_load(){ return "/players/goldsun/obj/sun_key:"; }

prevent_insert(){ return 1; }

drop(){
 return 1;
}

