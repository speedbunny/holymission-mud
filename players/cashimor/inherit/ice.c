/* ICE.C - Programmed by Ethereal Cashimor */
/* 150793: Started programming */

inherit "players/cashimor/inherit/special";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    envname="ice";
    wrtmsg="It's too slippery to move that way!";
    saymsg="Tries to move, but slippers back.";
    survivor="allows_skating";
  }
}
                                                              
