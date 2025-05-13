inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("dagger");
     set_short("Elizabeth Bathory's dagger");       
     set_long("This is the infamous dagger of the Elizabeth Bathory.  She used it "+
	      "for draining her victims' blood for her blood baths.\n");
     set_class(10);
     set_weight(2);
     set_value(3000);
  }
}
