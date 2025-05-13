inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc=("Queen Rhianna's Study.\n");
long_desc=("This is the study of Queen Rhianna. She would not be happy if she saw you in\n"+
"here. The room is furnished tasteful and elegant, but not too expensive. The \n"+
"walls are painted in plain white, on the north wall is a big painting, to \n"+
"the east you can see a window that over looks the beautiful garden park.\n"+
"The floor is covered with a purple carpet and a large writing desk catches your\n"+
"eyes. There is also a large multishelf bookcase and chest in room.\n"+
"A little stove spreading warmth throughout the room.\n");
items=({
"painting","The painting is a potrait of Rhianna's parents",
"stove","The stove is small and black and it's giving off some heat",
"carpet","The carpet is purple and plush",
"chest","This a small and obviously locked chest",
"bookcase","This an oak bookcase with 5 shelves on it",
"shelves","Which shelf would you like there are 5 of them",
"shelf 1","This shelf contains plays and sonnets of Shakepeare",
"shelf 2","This shelf contains books on etiquette",
"shelf 3","This shelf contains books of this lands history",
"shelf 4","This shelf is bare and has a lot of dust on it",
"shelf 5","This shelf has one book on it titled, Magic ",
"desk","The desk has papers scattered about it and an inkwell with "+
"a quill still in it",
"inkwell","The inkwell is small and half full",
"quill","The quill is a feather from a large bird",
});
}
