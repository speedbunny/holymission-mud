inherit "obj/key";

reset(arg){
 ::reset();
 if (arg) return;
 set_type("iron");
 set_code("zap");
}

drop(){
 write("The key crumblest to the dust.\n");
 destruct(this_object());
 return 1;
}
