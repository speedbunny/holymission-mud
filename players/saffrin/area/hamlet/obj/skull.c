inherit "obj/weapon";
      
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("skull");
     set_short("Yorick's skull");
    set_long("This is the infamous skull of poor Yorick.  Everyone knew him well.  There is\n"+
                    "some graveyard dirt on its teeth. \n");
     set_class(5);
     set_weight(1);
     set_value(2000);
  }
}

