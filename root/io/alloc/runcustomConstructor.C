{
// Fill out the code of the actual test
   gSystem->Load("customConstructor");
   TClass *c;

   c = gROOT->GetClass("None");
   c->New();

   c = gROOT->GetClass("Regular");
   c->New();

   c = gROOT->GetClass("G4");
   c->New();

   c = gROOT->GetClass("Private");
   c->New();

   c = gROOT->GetClass("Other");
   c->New();

   c = gROOT->GetClass("Default");
   c->New();

   c = gROOT->GetClass("Typedef");
   c->New();

   c = gROOT->GetClass("Pointers");
   c->New();

   c = gROOT->GetClass("WithTemplate");
   c->New();

   return 0;
}
