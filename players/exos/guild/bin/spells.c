#include "mage.h"

int main( string str ) {
    if( str )
	return ( 0 );
    write( "\n\
===================================================================\n\
LEVEL ONE             LEVEL TWO                LEVEL THREE\n\
---------             ---------                -----------\n\
Color Spray(20)       Acid Arrow(50)           Continual Light(60)\n\
Detect Invisible(30)  Armor(40)                Fireball(80)\n\
Light(20)             Invisibility(50)         Melt(60)\n\
Magic Missile(30)     Knock(40)                Mirror Image(60)\n\
Shield(30)            Ray of Enfeeblement(40)  Wizard Eye(60)\n\
\n\
LEVEL FOUR            LEVEL FIVE               LEVEL SIX\n\
----------            ----------               ---------\n\
Fear(80)              Cone of Cold(100)        Chain Lightning(150)\n\
Haste(120)            Fireshield(150)          Stoneskin(150)\n\
Hold Monster(80)      Infravision(80)          Teleport(150)\n\
Lightning Bolt(80)\n\
Strength(100)\n\
\n\
LEVEL SEVEN           LEVEL EIGHT              LEVEL NINE\n\
-----------           -----------              ----------\n\
Disintegrate(150)     Crushing Hand(200)       Gate(200)\n\
True Sight(100)       Scry(100)                Meteor Shower(250)\n\
==================================================================\n");
    return ( 1 );
}
