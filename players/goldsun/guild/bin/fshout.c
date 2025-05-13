#include "/obj/lw.h"
fshout(string str) {
	string shout,shoutinvis,shoutvis;
	object *u,tp,i,size,level;
	if(!str) { notify_fail("Shout what?\n");
		   return 0;
	}
	tp=this_player();
	if(tp->query_sp()<16) {
	 write("You do not have enough mental energy to do a fighters shout.\n");
	 return 1;
	}
	tp->restore_spell_points(-16);
	level=tp->query_level();
	switch(level) {
		case 1..5:
                 shout="A voice is propelled across the Mission and as it approaches, you reconize it as that of %p as "+tp->query_pronoun()+" shouts: ";
		 break;
		case 6..10:
		 shout="%p`s voice ripples across the lands of the Mission and the words which are formed are: ";
		 break;
		case 11..15:
		 shout="%p`s voice murmours around your body until finally exploding into the words: ";
		 break;
		case 16..20:
		 shout="%p`s vocal chords vibrate the ground you are standing on and the words that echo through your body are: ";
		 break;
		case 21..25:
		 shout="The voice of %p rings through the heavens with a noise so deafening that you can only just make out the words: ";
		 break;
		case 26..28:
		 shout="A cold wind blows across your face and your body chills as %p`s voice calls out the words: ";
		 break;
		default:
		 shout="%p screams in agony as "+tp->query_pronoun()+" throws "+tp->query_possessive()+" voice towards the sky and a moment later it echos back with the words: ";
	}
	write(lw("You shout: "+str+"\n"));
	shout+=(str+"\n");
	shoutinvis=implode(explode(shout,"%p"),"Someone");
	shoutvis=implode(explode(shout,"%p"),
		capitalize(tp->query_real_name()));
	u=users();
	size=sizeof(u);
	for(i=0;i<size;i++) {
	  if(u[i]->query_earmuff_level()>level || tp==u[i]) continue;
	  if(tp->is_invis_for(u[i])) tell_object(u[i],lw(shoutinvis));
	  else			     tell_object(u[i],lw(shoutvis));
	}
	return 1;
}
