inherit "/obj/thing";

object home;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("interior");
    set_long("An interior.\n");
    set_weight(0);
    home = 0;
  } else {
    object env;
    env = environment(this_object());
    if (!((home && (home == env)) || environment(env)))
      destruct(this_object());
  }
}

set_home(h) {home = (h)?h : environment(this_object());}

id (str) {
  return ::id(str) || ((str=="lighted_torch") && (name=="brazier"));
}

config(version,h) {
  string *str;
  int *ints,i;
  
  set_home(h);
  
  str = ({ "mirror","goblet","poker","crest","tapestry",
    "table","brazier","couch","chair","painting",
    "ashtray","bowl","nightstand","bed","table",
    "chair"});

  i = member_array(version,str);
  if (i>=0) {
  
  set_name(version);
  
  set_short( (((version[0]=="a")||(version[0]=="e")||(version[0]=="i")
  ||(version[0]=="o")||(version[0]=="u"))?
    "An ":"A " ) + version);
     
  str =({"The frame of this fine mirror is laced with silver and gold.\n",
    "It's a pewter goblet which glows with a lustrous shine.\n",
    "It's a black iron poker. It is used to stir the embers of an ongoing fire.\n",
    "It's the family crest of druid Lakmir himself.\n",
    "This hanging tapestry is made of the finest silk that comes exclusively\n"
      +"from the isle of Minar Togan.\n",
    
    "This small wooden table is made of a hardwood commonly found in the\n"
      +"Torlin Forest.\n",
    "This finely carved brazier is some six feet tall.\n"
      +"A flame burns within it, illuminating the entire room.\n",
    "This couch looks comfortable. \n"
      +"It is just long enough for you to lie down and stretch out upon.\n",
    "It is an early druidic chair -- very old and very valuable.\n"
       +"It looks soft and plushy.\n",
    "This painting depicts a mighty python wrapping itself around a rather\n"
      +"large ruby.\n",
    
    "It's a glass ashtray. It definitely did not come from a Holiday Inn.\n",
    "This silver bowl has been used by some slob as a spittoon.\n"
      +"It smells like old chaw. Disgusting.\n",
    "The solid-looking nightstand makes a hollow ring when you knock on it.\n",
    "A large luxurious bed -- definitely king-sized.\n",
    "It's a very sturdy wooden table that is some three inches thick.\n",
    
    "It's a very sturdy wooden chair which must have been made for heavy people.\n"});
  
  set_long(str[i]);
  
  ints=({0,1,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 0});
  set_light(ints[i]);
  
  ints=({1,1,1,0,0, 0,0,0,0,1, 1,1,0,0,0, 0});
  set_can_get(ints[i]);

  ints=({2,1,2,0,0, 0,0,0,0,2, 1,1,0,0,0, 0});
  set_weight(ints[i]);
  
  }
  return (this_object());
}
