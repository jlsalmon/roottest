Int_t runFileStagerTest()
{
  std::cout << "Beginning FileStagerTest" << std::endl;
  TString server = "root://vagabond.cern.ch/";

  TFileStager *s  = TFileStager::Open( server );

  // IsStaged()
  Bool_t isStaged = s->IsStaged( server + "/tmp/nonexisting.root" );
  std::cout << "File is staged: " << ( isStaged ? "true" : "false" ) << std::endl;
  Bool_t isStaged = s->IsStaged( server + "/tmp/Event.root" );
  std::cout << "File is staged: " << ( isStaged ? "true" : "false" ) << std::endl;

  // Locate()
  TString endpoint = 0;
  if( s->Locate( server + "/tmp/Event.root", endpoint ) != 0 )
  {
    std::cout << "Error locating file" << std::endl;
    return 1;
  }
  std::cout << "Endpoint: " << endpoint << std::endl;

  // LocateCollection()

  // Matches()

  // Stage() single
  if( s->Stage( server + "/tmp/Event.root" ) != 0 )
  {
    std::cout << "Error staging single" << std::endl;
    return 1;
  }

  // Stage() multiple
  TList t = TList();
  t.Add( (TObject*) TUrl( server + "/tmp/Event.root" ) );
  t.Add( (TObject*) TUrl( server + "/tmp/atlasFlushed.root" ) );
  if( s->Stage( (TCollection*) t, "priority=1" ) != 0 )
  {
    std::cout << "Error staging multiple" << std::endl;
    return 1;
  }
  return 0;
}

