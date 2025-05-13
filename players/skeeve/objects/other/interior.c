inherit "/obj/thing";

object home;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("interior");
    set_short("An interior");
    set_long("An interior.\n");
    set_weight(2);
    home = environment(this_object());
  } else {
    object env;
    if ( (home != (env = environment(this_object()))) && !environment(env))
      destruct(this_object());
  }
}

config(version,h) {
  if (h) home = h;
  switch(version) {
    case "mirror":
       set_name("mirror");
       set_long("The frame of this fine mirror is laced with silver and gold.\n");
    break;
    case "goblet":
       set_name("goblet");
       set_long("It's a pewter goblet which glows with a lustrous shine.\n");
       set_light(1);
    break;
    case "poker": 
       set_name("poker");
       set_long("It's a black iron poker. "
               +"It is used to stir the embers of an ongoing fire.\n");
    break;
    case "crest": 
       set_name("crest");
       set_long("It's the family crest of druid Lakmir himself.\n");
       set_can_get(0);
    break;
    case "tapestry": 
       set_name("tapestry");
       set_long("This hanging tapestry is made of the finest silk that comes exclusively\n"
               +"from the isle of Minar Togan.\n");
       set_can_get(0);
    break;
    case "table": 
       set_name("table");
       set_long("This small wooden table is made of a hardwood commonly found in the\n"
               +"Torlin Forest.\n");
       set_can_get(0);
    break;
    case "brazier": 
       set_name("brazier");
       set_long("This finely carved brazier is some six feet tall.\n"
               +"A flame burns within it, illuminating the entire room.\n");
       set_light(1);
       set_can_get(0);
    break;
    case "couch": 
       set_name("couch");
       set_long("This couch looks comfortable. It is just long enough for "
               +"you to lie down and stretch out upon.\n");
       set_can_get(0);
    break;
    case "chair": 
       set_name("chair");
       set_long("It is an early druidic chair -- very old and very valuable.\n"
                +"It looks soft and plushy.\n");
       set_can_get(0);
    break;
    case "painting": 
       set_name("painting");
       set_long("This painting depicts a mighty python wrapping itself around a rather\n"
               +"large ruby.\n");
    break;
    case "ashtray": 
       set_name("ashtray");
       set_long("It's a glass ashtray. It definitely did not come from a Holiday Inn.\n");
    break;
    case "bowl": 
       set_name("bowl");
       set_long("This silver bowl has been used by some slob as a spittoon.\n"
               +"It smells like old chaw. Disgusting.\n");
    break;
    case "nightstand": 
       set_name("nightstand");
       set_long("The solid-looking nightstand makes a hollow ring when you knock on it.\n");
       set_can_get(0);
    break;
    case "bed": 
       set_name("bed");
       set_long("A large luxurious bed -- definitely king-sized.\n");
       set_can_get(0);
    break;
    case "guardroom table": 
       set_name("table");
       set_alias("guardroom table");
       set_long("It's a very sturdy wooden table that is some three inches thick.\n");
       set_can_get(0);
    break;
    case "guardroom chair": 
       set_name("chair");
       set_alias("guardroom chair");
       set_long("It's a very sturdy wooden chair which must have been made for heavy people.\n");
       set_can_get(0);
    break;
    default:
       set_name("Unknown interior");
  }
  set_short("A " + query_name());
  return this_object();
}
