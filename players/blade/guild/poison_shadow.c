
/* 930131 mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*--------------------------------------------*
 * Allow thieves to poison thier weapons.     *
 * The soul has to make sure that the right   *
 * equipment is used by the thief, and then   *
 * start the shadow.                          *
 * We assume that something compatible to     *
 * obj/weapon is used as weapon.              *
 *--------------------------------------------*/

object weapon;
int strength;

start_shadow(object obj,int d,int s) {
  weapon=obj;
  strength=s;
  shadow(obj,1);		/* Start shadowing now */
  call_out("remove_shadow",d);
}

remove_shadow() {
object env;

  if ((env=environment(weapon)) && interactive(env)) 
      tell_object(env,"The poison on the "+weapon->short()+" dries up.\n");
  destruct(this_object());
}

/* Overwrite obj/weapon::hit() here */

hit(attacker) {

  attacker->add_poison(random(strength));	/* Do poisoning */
  weapon->hit(attacker);			/* and call original function */

}

/* Overwrite obj/weapon::short() here */

short() { return weapon->short()+" (poisoned)"; }

/* Create new function query_poison_shadow() */

int query_poison_shadow(){
return 1;
}






