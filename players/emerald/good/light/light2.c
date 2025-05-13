inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Bright field";
  long_desc="The bright colours of blooming flowers greet your eyes from "+
            "every direction.  The scent of roses wafts upwards on a light "+
            "western breeze.  Far, far away to the north rises the snowy "+
            "peak of an ancient mountain.\n";

  items=({"roses","The roses are VERY bright and pretty",
          "flowers","Roses are the only type of flowers",
          "peak","It looks like it would be hard to climb with all that snow",
          "mountain","That mountain is really huge",
        });

  smell="The delicious scent of roses.";
  dest_dir=({"players/emerald/good/light/light3","north",
             "players/emerald/good/light/light1","south",
           });

  ::reset();
  replace_program("/room/room");

}
