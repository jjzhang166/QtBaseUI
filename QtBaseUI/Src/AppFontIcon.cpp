#include "stdafx.h"

#include "AppFontIcon.h"

#include "AppFontIconAnim.h"

#include <QDebug>
#include <QFile>
#include <QFontDatabase>
#include <QScopedPointer>

//----------------------------------------------------------------------------------------------------------------------------

struct stFaNameIcon 
{
  const char *name;
  faIcon::icon icon;
};

static const stFaNameIcon faNameIconArray[] = 
{
      { "fa_500px"                         , faIcon::fa_500px                         },
      { "addressbook"                      , faIcon::addressbook                      },
      { "addressbooko"                     , faIcon::addressbooko                     },
      { "addresscard"                      , faIcon::addresscard                      },
      { "addresscardo"                     , faIcon::addresscardo                     },
      { "adjust"                           , faIcon::adjust                           },
      { "adn"                              , faIcon::adn                              },
      { "aligncenter"                      , faIcon::aligncenter                      },
      { "alignjustify"                     , faIcon::alignjustify                     },
      { "alignleft"                        , faIcon::alignleft                        },
      { "alignright"                       , faIcon::alignright                       },
      { "amazon"                           , faIcon::amazon                           },
      { "ambulance"                        , faIcon::ambulance                        },
      { "americansignlanguageinterpreting" , faIcon::americansignlanguageinterpreting },
      { "anchor"                           , faIcon::anchor                           },
      { "android"                          , faIcon::android                          },
      { "angellist"                        , faIcon::angellist                        },
      { "angledoubledown"                  , faIcon::angledoubledown                  },
      { "angledoubleleft"                  , faIcon::angledoubleleft                  },
      { "angledoubleright"                 , faIcon::angledoubleright                 },
      { "angledoubleup"                    , faIcon::angledoubleup                    },
      { "angledown"                        , faIcon::angledown                        },
      { "angleleft"                        , faIcon::angleleft                        },
      { "angleright"                       , faIcon::angleright                       },
      { "angleup"                          , faIcon::angleup                          },
      { "apple"                            , faIcon::apple                            },
      { "archive"                          , faIcon::archive                          },
      { "areachart"                        , faIcon::areachart                        },
      { "arrowcircledown"                  , faIcon::arrowcircledown                  },
      { "arrowcircleleft"                  , faIcon::arrowcircleleft                  },
      { "arrowcircleodown"                 , faIcon::arrowcircleodown                 },
      { "arrowcircleoleft"                 , faIcon::arrowcircleoleft                 },
      { "arrowcircleoright"                , faIcon::arrowcircleoright                },
      { "arrowcircleoup"                   , faIcon::arrowcircleoup                   },
      { "arrowcircleright"                 , faIcon::arrowcircleright                 },
      { "arrowcircleup"                    , faIcon::arrowcircleup                    },
      { "arrowdown"                        , faIcon::arrowdown                        },
      { "arrowleft"                        , faIcon::arrowleft                        },
      { "arrowright"                       , faIcon::arrowright                       },
      { "arrowup"                          , faIcon::arrowup                          },
      { "arrows"                           , faIcon::arrows                           },
      { "arrowsalt"                        , faIcon::arrowsalt                        },
      { "arrowsh"                          , faIcon::arrowsh                          },
      { "arrowsv"                          , faIcon::arrowsv                          },
      { "aslinterpreting"                  , faIcon::aslinterpreting                  },
      { "assistivelisteningsystems"        , faIcon::assistivelisteningsystems        },
      { "asterisk"                         , faIcon::asterisk                         },
      { "at"                               , faIcon::at                               },
      { "audiodescription"                 , faIcon::audiodescription                 },
      { "automobile"                       , faIcon::automobile                       },
      { "backward"                         , faIcon::backward                         },
      { "balancescale"                     , faIcon::balancescale                     },
      { "ban"                              , faIcon::ban                              },
      { "bandcamp"                         , faIcon::bandcamp                         },
      { "bank"                             , faIcon::bank                             },
      { "barchart"                         , faIcon::barchart                         },
      { "barcharto"                        , faIcon::barcharto                        },
      { "barcode"                          , faIcon::barcode                          },
      { "bars"                             , faIcon::bars                             },
      { "bath"                             , faIcon::bath                             },
      { "bathtub"                          , faIcon::bathtub                          },
      { "battery"                          , faIcon::battery                          },
      { "battery0"                         , faIcon::battery0                         },
      { "battery1"                         , faIcon::battery1                         },
      { "battery2"                         , faIcon::battery2                         },
      { "battery3"                         , faIcon::battery3                         },
      { "battery4"                         , faIcon::battery4                         },
      { "batteryempty"                     , faIcon::batteryempty                     },
      { "batteryfull"                      , faIcon::batteryfull                      },
      { "batteryhalf"                      , faIcon::batteryhalf                      },
      { "batteryquarter"                   , faIcon::batteryquarter                   },
      { "batterythreequarters"             , faIcon::batterythreequarters             },
      { "bed"                              , faIcon::bed                              },
      { "beer"                             , faIcon::beer                             },
      { "behance"                          , faIcon::behance                          },
      { "behancesquare"                    , faIcon::behancesquare                    },
      { "bell"                             , faIcon::bell                             },
      { "bello"                            , faIcon::bello                            },
      { "bellslash"                        , faIcon::bellslash                        },
      { "bellslasho"                       , faIcon::bellslasho                       },
      { "bicycle"                          , faIcon::bicycle                          },
      { "binoculars"                       , faIcon::binoculars                       },
      { "birthdaycake"                     , faIcon::birthdaycake                     },
      { "bitbucket"                        , faIcon::bitbucket                        },
      { "bitbucketsquare"                  , faIcon::bitbucketsquare                  },
      { "bitcoin"                          , faIcon::bitcoin                          },
      { "blacktie"                         , faIcon::blacktie                         },
      { "blind"                            , faIcon::blind                            },
      { "bluetooth"                        , faIcon::bluetooth                        },
      { "bluetoothb"                       , faIcon::bluetoothb                       },
      { "bold"                             , faIcon::bold                             },
      { "bolt"                             , faIcon::bolt                             },
      { "bomb"                             , faIcon::bomb                             },
      { "book"                             , faIcon::book                             },
      { "bookmark"                         , faIcon::bookmark                         },
      { "bookmarko"                        , faIcon::bookmarko                        },
      { "braille"                          , faIcon::braille                          },
      { "briefcase"                        , faIcon::briefcase                        },
      { "btc"                              , faIcon::btc                              },
      { "bug"                              , faIcon::bug                              },
      { "building"                         , faIcon::building                         },
      { "buildingo"                        , faIcon::buildingo                        },
      { "bullhorn"                         , faIcon::bullhorn                         },
      { "bullseye"                         , faIcon::bullseye                         },
      { "bus"                              , faIcon::bus                              },
      { "buysellads"                       , faIcon::buysellads                       },
      { "cab"                              , faIcon::cab                              },
      { "calculator"                       , faIcon::calculator                       },
      { "calendar"                         , faIcon::calendar                         },
      { "calendarchecko"                   , faIcon::calendarchecko                   },
      { "calendarminuso"                   , faIcon::calendarminuso                   },
      { "calendaro"                        , faIcon::calendaro                        },
      { "calendarpluso"                    , faIcon::calendarpluso                    },
      { "calendartimeso"                   , faIcon::calendartimeso                   },
      { "camera"                           , faIcon::camera                           },
      { "cameraretro"                      , faIcon::cameraretro                      },
      { "car"                              , faIcon::car                              },
      { "caretdown"                        , faIcon::caretdown                        },
      { "caretleft"                        , faIcon::caretleft                        },
      { "caretright"                       , faIcon::caretright                       },
      { "caretsquareodown"                 , faIcon::caretsquareodown                 },
      { "caretsquareoleft"                 , faIcon::caretsquareoleft                 },
      { "caretsquareoright"                , faIcon::caretsquareoright                },
      { "caretsquareoup"                   , faIcon::caretsquareoup                   },
      { "caretup"                          , faIcon::caretup                          },
      { "cartarrowdown"                    , faIcon::cartarrowdown                    },
      { "cartplus"                         , faIcon::cartplus                         },
      { "cc"                               , faIcon::cc                               },
      { "ccamex"                           , faIcon::ccamex                           },
      { "ccdinersclub"                     , faIcon::ccdinersclub                     },
      { "ccdiscover"                       , faIcon::ccdiscover                       },
      { "ccjcb"                            , faIcon::ccjcb                            },
      { "ccmastercard"                     , faIcon::ccmastercard                     },
      { "ccpaypal"                         , faIcon::ccpaypal                         },
      { "ccstripe"                         , faIcon::ccstripe                         },
      { "ccvisa"                           , faIcon::ccvisa                           },
      { "certificate"                      , faIcon::certificate                      },
      { "chain"                            , faIcon::chain                            },
      { "chainbroken"                      , faIcon::chainbroken                      },
      { "check"                            , faIcon::check                            },
      { "checkcircle"                      , faIcon::checkcircle                      },
      { "checkcircleo"                     , faIcon::checkcircleo                     },
      { "checksquare"                      , faIcon::checksquare                      },
      { "checksquareo"                     , faIcon::checksquareo                     },
      { "chevroncircledown"                , faIcon::chevroncircledown                },
      { "chevroncircleleft"                , faIcon::chevroncircleleft                },
      { "chevroncircleright"               , faIcon::chevroncircleright               },
      { "chevroncircleup"                  , faIcon::chevroncircleup                  },
      { "chevrondown"                      , faIcon::chevrondown                      },
      { "chevronleft"                      , faIcon::chevronleft                      },
      { "chevronright"                     , faIcon::chevronright                     },
      { "chevronup"                        , faIcon::chevronup                        },
      { "child"                            , faIcon::child                            },
      { "chrome"                           , faIcon::chrome                           },
      { "circle"                           , faIcon::circle                           },
      { "circleo"                          , faIcon::circleo                          },
      { "circleonotch"                     , faIcon::circleonotch                     },
      { "circlethin"                       , faIcon::circlethin                       },
      { "clipboard"                        , faIcon::clipboard                        },
      { "clocko"                           , faIcon::clocko                           },
      { "clone"                            , faIcon::clone                            },
      { "close"                            , faIcon::close                            },
      { "cloud"                            , faIcon::cloud                            },
      { "clouddownload"                    , faIcon::clouddownload                    },
      { "cloudupload"                      , faIcon::cloudupload                      },
      { "cny"                              , faIcon::cny                              },
      { "code"                             , faIcon::code                             },
      { "codefork"                         , faIcon::codefork                         },
      { "codepen"                          , faIcon::codepen                          },
      { "codiepie"                         , faIcon::codiepie                         },
      { "coffee"                           , faIcon::coffee                           },
      { "cog"                              , faIcon::cog                              },
      { "cogs"                             , faIcon::cogs                             },
      { "columns"                          , faIcon::columns                          },
      { "comment"                          , faIcon::comment                          },
      { "commento"                         , faIcon::commento                         },
      { "commenting"                       , faIcon::commenting                       },
      { "commentingo"                      , faIcon::commentingo                      },
      { "comments"                         , faIcon::comments                         },
      { "commentso"                        , faIcon::commentso                        },
      { "compass"                          , faIcon::compass                          },
      { "compress"                         , faIcon::compress                         },
      { "connectdevelop"                   , faIcon::connectdevelop                   },
      { "contao"                           , faIcon::contao                           },
      { "copy"                             , faIcon::copy                             },
      { "copyright"                        , faIcon::copyright                        },
      { "creativecommons"                  , faIcon::creativecommons                  },
      { "creditcard"                       , faIcon::creditcard                       },
      { "creditcardalt"                    , faIcon::creditcardalt                    },
      { "crop"                             , faIcon::crop                             },
      { "crosshairs"                       , faIcon::crosshairs                       },
      { "css3"                             , faIcon::css3                             },
      { "cube"                             , faIcon::cube                             },
      { "cubes"                            , faIcon::cubes                            },
      { "cut"                              , faIcon::cut                              },
      { "cutlery"                          , faIcon::cutlery                          },
      { "dashboard"                        , faIcon::dashboard                        },
      { "dashcube"                         , faIcon::dashcube                         },
      { "database"                         , faIcon::database                         },
      { "deaf"                             , faIcon::deaf                             },
      { "deafness"                         , faIcon::deafness                         },
      { "dedent"                           , faIcon::dedent                           },
      { "delicious"                        , faIcon::delicious                        },
      { "desktop"                          , faIcon::desktop                          },
      { "deviantart"                       , faIcon::deviantart                       },
      { "diamond"                          , faIcon::diamond                          },
      { "digg"                             , faIcon::digg                             },
      { "dollar"                           , faIcon::dollar                           },
      { "dotcircleo"                       , faIcon::dotcircleo                       },
      { "download"                         , faIcon::download                         },
      { "dribbble"                         , faIcon::dribbble                         },
      { "driverslicense"                   , faIcon::driverslicense                   },
      { "driverslicenseo"                  , faIcon::driverslicenseo                  },
      { "dropbox"                          , faIcon::dropbox                          },
      { "drupal"                           , faIcon::drupal                           },
      { "edge"                             , faIcon::edge                             },
      { "edit"                             , faIcon::edit                             },
      { "eercast"                          , faIcon::eercast                          },
      { "eject"                            , faIcon::eject                            },
      { "ellipsish"                        , faIcon::ellipsish                        },
      { "ellipsisv"                        , faIcon::ellipsisv                        },
      { "empire"                           , faIcon::empire                           },
      { "envelope"                         , faIcon::envelope                         },
      { "envelopeo"                        , faIcon::envelopeo                        },
      { "envelopeopen"                     , faIcon::envelopeopen                     },
      { "envelopeopeno"                    , faIcon::envelopeopeno                    },
      { "envelopesquare"                   , faIcon::envelopesquare                   },
      { "envira"                           , faIcon::envira                           },
      { "eraser"                           , faIcon::eraser                           },
      { "etsy"                             , faIcon::etsy                             },
      { "eur"                              , faIcon::eur                              },
      { "euro"                             , faIcon::euro                             },
      { "exchange"                         , faIcon::exchange                         },
      { "exclamation"                      , faIcon::exclamation                      },
      { "exclamationcircle"                , faIcon::exclamationcircle                },
      { "exclamationtriangle"              , faIcon::exclamationtriangle              },
      { "expand"                           , faIcon::expand                           },
      { "expeditedssl"                     , faIcon::expeditedssl                     },
      { "externallink"                     , faIcon::externallink                     },
      { "externallinksquare"               , faIcon::externallinksquare               },
      { "eye"                              , faIcon::eye                              },
      { "eyeslash"                         , faIcon::eyeslash                         },
      { "eyedropper"                       , faIcon::eyedropper                       },
      { "fa"                               , faIcon::fa                               },
      { "facebook"                         , faIcon::facebook                         },
      { "facebookf"                        , faIcon::facebookf                        },
      { "facebookofficial"                 , faIcon::facebookofficial                 },
      { "facebooksquare"                   , faIcon::facebooksquare                   },
      { "fastbackward"                     , faIcon::fastbackward                     },
      { "fastforward"                      , faIcon::fastforward                      },
      { "fax"                              , faIcon::fax                              },
      { "feed"                             , faIcon::feed                             },
      { "female"                           , faIcon::female                           },
      { "fighterjet"                       , faIcon::fighterjet                       },
      { "file"                             , faIcon::file                             },
      { "filearchiveo"                     , faIcon::filearchiveo                     },
      { "fileaudioo"                       , faIcon::fileaudioo                       },
      { "filecodeo"                        , faIcon::filecodeo                        },
      { "fileexcelo"                       , faIcon::fileexcelo                       },
      { "fileimageo"                       , faIcon::fileimageo                       },
      { "filemovieo"                       , faIcon::filemovieo                       },
      { "fileo"                            , faIcon::fileo                            },
      { "filepdfo"                         , faIcon::filepdfo                         },
      { "filephotoo"                       , faIcon::filephotoo                       },
      { "filepictureo"                     , faIcon::filepictureo                     },
      { "filepowerpointo"                  , faIcon::filepowerpointo                  },
      { "filesoundo"                       , faIcon::filesoundo                       },
      { "filetext"                         , faIcon::filetext                         },
      { "filetexto"                        , faIcon::filetexto                        },
      { "filevideoo"                       , faIcon::filevideoo                       },
      { "filewordo"                        , faIcon::filewordo                        },
      { "filezipo"                         , faIcon::filezipo                         },
      { "fileso"                           , faIcon::fileso                           },
      { "film"                             , faIcon::film                             },
      { "filter"                           , faIcon::filter                           },
      { "fire"                             , faIcon::fire                             },
      { "fireextinguisher"                 , faIcon::fireextinguisher                 },
      { "firefox"                          , faIcon::firefox                          },
      { "firstorder"                       , faIcon::firstorder                       },
      { "flag"                             , faIcon::flag                             },
      { "flagcheckered"                    , faIcon::flagcheckered                    },
      { "flago"                            , faIcon::flago                            },
      { "flash"                            , faIcon::flash                            },
      { "flask"                            , faIcon::flask                            },
      { "flickr"                           , faIcon::flickr                           },
      { "floppyo"                          , faIcon::floppyo                          },
      { "folder"                           , faIcon::folder                           },
      { "foldero"                          , faIcon::foldero                          },
      { "folderopen"                       , faIcon::folderopen                       },
      { "folderopeno"                      , faIcon::folderopeno                      },
      { "font"                             , faIcon::font                             },
      { "fontawesome"                      , faIcon::fontawesome                      },
      { "fonticons"                        , faIcon::fonticons                        },
      { "fortawesome"                      , faIcon::fortawesome                      },
      { "forumbee"                         , faIcon::forumbee                         },
      { "forward"                          , faIcon::forward                          },
      { "foursquare"                       , faIcon::foursquare                       },
      { "freecodecamp"                     , faIcon::freecodecamp                     },
      { "frowno"                           , faIcon::frowno                           },
      { "futbolo"                          , faIcon::futbolo                          },
      { "gamepad"                          , faIcon::gamepad                          },
      { "gavel"                            , faIcon::gavel                            },
      { "gbp"                              , faIcon::gbp                              },
      { "ge"                               , faIcon::ge                               },
      { "gear"                             , faIcon::gear                             },
      { "gears"                            , faIcon::gears                            },
      { "genderless"                       , faIcon::genderless                       },
      { "getpocket"                        , faIcon::getpocket                        },
      { "gg"                               , faIcon::gg                               },
      { "ggcircle"                         , faIcon::ggcircle                         },
      { "gift"                             , faIcon::gift                             },
      { "git"                              , faIcon::git                              },
      { "gitsquare"                        , faIcon::gitsquare                        },
      { "github"                           , faIcon::github                           },
      { "githubalt"                        , faIcon::githubalt                        },
      { "githubsquare"                     , faIcon::githubsquare                     },
      { "gitlab"                           , faIcon::gitlab                           },
      { "gittip"                           , faIcon::gittip                           },
      { "glass"                            , faIcon::glass                            },
      { "glide"                            , faIcon::glide                            },
      { "glideg"                           , faIcon::glideg                           },
      { "globe"                            , faIcon::globe                            },
      { "google"                           , faIcon::google                           },
      { "googleplus"                       , faIcon::googleplus                       },
      { "googlepluscircle"                 , faIcon::googlepluscircle                 },
      { "googleplusofficial"               , faIcon::googleplusofficial               },
      { "googleplussquare"                 , faIcon::googleplussquare                 },
      { "googlewallet"                     , faIcon::googlewallet                     },
      { "graduationcap"                    , faIcon::graduationcap                    },
      { "gratipay"                         , faIcon::gratipay                         },
      { "grav"                             , faIcon::grav                             },
      { "group"                            , faIcon::group                            },
      { "hsquare"                          , faIcon::hsquare                          },
      { "hackernews"                       , faIcon::hackernews                       },
      { "handgrabo"                        , faIcon::handgrabo                        },
      { "handlizardo"                      , faIcon::handlizardo                      },
      { "handodown"                        , faIcon::handodown                        },
      { "handoleft"                        , faIcon::handoleft                        },
      { "handoright"                       , faIcon::handoright                       },
      { "handoup"                          , faIcon::handoup                          },
      { "handpapero"                       , faIcon::handpapero                       },
      { "handpeaceo"                       , faIcon::handpeaceo                       },
      { "handpointero"                     , faIcon::handpointero                     },
      { "handrocko"                        , faIcon::handrocko                        },
      { "handscissorso"                    , faIcon::handscissorso                    },
      { "handspocko"                       , faIcon::handspocko                       },
      { "handstopo"                        , faIcon::handstopo                        },
      { "handshakeo"                       , faIcon::handshakeo                       },
      { "hardofhearing"                    , faIcon::hardofhearing                    },
      { "hashtag"                          , faIcon::hashtag                          },
      { "hddo"                             , faIcon::hddo                             },
      { "header"                           , faIcon::header                           },
      { "headphones"                       , faIcon::headphones                       },
      { "heart"                            , faIcon::heart                            },
      { "hearto"                           , faIcon::hearto                           },
      { "heartbeat"                        , faIcon::heartbeat                        },
      { "history"                          , faIcon::history                          },
      { "home"                             , faIcon::home                             },
      { "hospitalo"                        , faIcon::hospitalo                        },
      { "hotel"                            , faIcon::hotel                            },
      { "hourglass"                        , faIcon::hourglass                        },
      { "hourglass1"                       , faIcon::hourglass1                       },
      { "hourglass2"                       , faIcon::hourglass2                       },
      { "hourglass3"                       , faIcon::hourglass3                       },
      { "hourglassend"                     , faIcon::hourglassend                     },
      { "hourglasshalf"                    , faIcon::hourglasshalf                    },
      { "hourglasso"                       , faIcon::hourglasso                       },
      { "hourglassstart"                   , faIcon::hourglassstart                   },
      { "houzz"                            , faIcon::houzz                            },
      { "html5"                            , faIcon::html5                            },
      { "icursor"                          , faIcon::icursor                          },
      { "idbadge"                          , faIcon::idbadge                          },
      { "idcard"                           , faIcon::idcard                           },
      { "idcardo"                          , faIcon::idcardo                          },
      { "ils"                              , faIcon::ils                              },
      { "image"                            , faIcon::image                            },
      { "imdb"                             , faIcon::imdb                             },
      { "inbox"                            , faIcon::inbox                            },
      { "indent"                           , faIcon::indent                           },
      { "industry"                         , faIcon::industry                         },
      { "info"                             , faIcon::info                             },
      { "infocircle"                       , faIcon::infocircle                       },
      { "inr"                              , faIcon::inr                              },
      { "instagram"                        , faIcon::instagram                        },
      { "institution"                      , faIcon::institution                      },
      { "internetexplorer"                 , faIcon::internetexplorer                 },
      { "intersex"                         , faIcon::intersex                         },
      { "ioxhost"                          , faIcon::ioxhost                          },
      { "italic"                           , faIcon::italic                           },
      { "joomla"                           , faIcon::joomla                           },
      { "jpy"                              , faIcon::jpy                              },
      { "jsfiddle"                         , faIcon::jsfiddle                         },
      { "key"                              , faIcon::key                              },
      { "keyboardo"                        , faIcon::keyboardo                        },
      { "krw"                              , faIcon::krw                              },
      { "language"                         , faIcon::language                         },
      { "laptop"                           , faIcon::laptop                           },
      { "lastfm"                           , faIcon::lastfm                           },
      { "lastfmsquare"                     , faIcon::lastfmsquare                     },
      { "leaf"                             , faIcon::leaf                             },
      { "leanpub"                          , faIcon::leanpub                          },
      { "legal"                            , faIcon::legal                            },
      { "lemono"                           , faIcon::lemono                           },
      { "leveldown"                        , faIcon::leveldown                        },
      { "levelup"                          , faIcon::levelup                          },
      { "lifebouy"                         , faIcon::lifebouy                         },
      { "lifebuoy"                         , faIcon::lifebuoy                         },
      { "lifering"                         , faIcon::lifering                         },
      { "lifesaver"                        , faIcon::lifesaver                        },
      { "lightbulbo"                       , faIcon::lightbulbo                       },
      { "linechart"                        , faIcon::linechart                        },
      { "link"                             , faIcon::link                             },
      { "linkedin"                         , faIcon::linkedin                         },
      { "linkedinsquare"                   , faIcon::linkedinsquare                   },
      { "linode"                           , faIcon::linode                           },
      { "fa_linux"                         , faIcon::fa_linux                         },
      { "list"                             , faIcon::list                             },
      { "listalt"                          , faIcon::listalt                          },
      { "listol"                           , faIcon::listol                           },
      { "listul"                           , faIcon::listul                           },
      { "locationarrow"                    , faIcon::locationarrow                    },
      { "lock"                             , faIcon::lock                             },
      { "longarrowdown"                    , faIcon::longarrowdown                    },
      { "longarrowleft"                    , faIcon::longarrowleft                    },
      { "longarrowright"                   , faIcon::longarrowright                   },
      { "longarrowup"                      , faIcon::longarrowup                      },
      { "lowvision"                        , faIcon::lowvision                        },
      { "magic"                            , faIcon::magic                            },
      { "magnet"                           , faIcon::magnet                           },
      { "mailforward"                      , faIcon::mailforward                      },
      { "mailreply"                        , faIcon::mailreply                        },
      { "mailreplyall"                     , faIcon::mailreplyall                     },
      { "male"                             , faIcon::male                             },
      { "map"                              , faIcon::map                              },
      { "mapmarker"                        , faIcon::mapmarker                        },
      { "mapo"                             , faIcon::mapo                             },
      { "mappin"                           , faIcon::mappin                           },
      { "mapsigns"                         , faIcon::mapsigns                         },
      { "mars"                             , faIcon::mars                             },
      { "marsdouble"                       , faIcon::marsdouble                       },
      { "marsstroke"                       , faIcon::marsstroke                       },
      { "marsstrokeh"                      , faIcon::marsstrokeh                      },
      { "marsstrokev"                      , faIcon::marsstrokev                      },
      { "maxcdn"                           , faIcon::maxcdn                           },
      { "meanpath"                         , faIcon::meanpath                         },
      { "medium"                           , faIcon::medium                           },
      { "medkit"                           , faIcon::medkit                           },
      { "meetup"                           , faIcon::meetup                           },
      { "meho"                             , faIcon::meho                             },
      { "mercury"                          , faIcon::mercury                          },
      { "microchip"                        , faIcon::microchip                        },
      { "microphone"                       , faIcon::microphone                       },
      { "microphoneslash"                  , faIcon::microphoneslash                  },
      { "minus"                            , faIcon::minus                            },
      { "minuscircle"                      , faIcon::minuscircle                      },
      { "minussquare"                      , faIcon::minussquare                      },
      { "minussquareo"                     , faIcon::minussquareo                     },
      { "mixcloud"                         , faIcon::mixcloud                         },
      { "mobile"                           , faIcon::mobile                           },
      { "mobilephone"                      , faIcon::mobilephone                      },
      { "modx"                             , faIcon::modx                             },
      { "money"                            , faIcon::money                            },
      { "moono"                            , faIcon::moono                            },
      { "mortarboard"                      , faIcon::mortarboard                      },
      { "motorcycle"                       , faIcon::motorcycle                       },
      { "mousepointer"                     , faIcon::mousepointer                     },
      { "music"                            , faIcon::music                            },
      { "navicon"                          , faIcon::navicon                          },
      { "neuter"                           , faIcon::neuter                           },
      { "newspapero"                       , faIcon::newspapero                       },
      { "objectgroup"                      , faIcon::objectgroup                      },
      { "objectungroup"                    , faIcon::objectungroup                    },
      { "odnoklassniki"                    , faIcon::odnoklassniki                    },
      { "odnoklassnikisquare"              , faIcon::odnoklassnikisquare              },
      { "opencart"                         , faIcon::opencart                         },
      { "openid"                           , faIcon::openid                           },
      { "opera"                            , faIcon::opera                            },
      { "optinmonster"                     , faIcon::optinmonster                     },
      { "outdent"                          , faIcon::outdent                          },
      { "pagelines"                        , faIcon::pagelines                        },
      { "paintbrush"                       , faIcon::paintbrush                       },
      { "paperplane"                       , faIcon::paperplane                       },
      { "paperplaneo"                      , faIcon::paperplaneo                      },
      { "paperclip"                        , faIcon::paperclip                        },
      { "paragraph"                        , faIcon::paragraph                        },
      { "paste"                            , faIcon::paste                            },
      { "pause"                            , faIcon::pause                            },
      { "pausecircle"                      , faIcon::pausecircle                      },
      { "pausecircleo"                     , faIcon::pausecircleo                     },
      { "paw"                              , faIcon::paw                              },
      { "paypal"                           , faIcon::paypal                           },
      { "pencil"                           , faIcon::pencil                           },
      { "pencilsquare"                     , faIcon::pencilsquare                     },
      { "pencilsquareo"                    , faIcon::pencilsquareo                    },
      { "percent"                          , faIcon::percent                          },
      { "phone"                            , faIcon::phone                            },
      { "phonesquare"                      , faIcon::phonesquare                      },
      { "photo"                            , faIcon::photo                            },
      { "pictureo"                         , faIcon::pictureo                         },
      { "piechart"                         , faIcon::piechart                         },
      { "piedpiper"                        , faIcon::piedpiper                        },
      { "piedpiperalt"                     , faIcon::piedpiperalt                     },
      { "piedpiperpp"                      , faIcon::piedpiperpp                      },
      { "pinterest"                        , faIcon::pinterest                        },
      { "pinterestp"                       , faIcon::pinterestp                       },
      { "pinterestsquare"                  , faIcon::pinterestsquare                  },
      { "plane"                            , faIcon::plane                            },
      { "play"                             , faIcon::play                             },
      { "playcircle"                       , faIcon::playcircle                       },
      { "playcircleo"                      , faIcon::playcircleo                      },
      { "plug"                             , faIcon::plug                             },
      { "plus"                             , faIcon::plus                             },
      { "pluscircle"                       , faIcon::pluscircle                       },
      { "plussquare"                       , faIcon::plussquare                       },
      { "plussquareo"                      , faIcon::plussquareo                      },
      { "podcast"                          , faIcon::podcast                          },
      { "poweroff"                         , faIcon::poweroff                         },
      { "print"                            , faIcon::print                            },
      { "producthunt"                      , faIcon::producthunt                      },
      { "puzzlepiece"                      , faIcon::puzzlepiece                      },
      { "qq"                               , faIcon::qq                               },
      { "qrcode"                           , faIcon::qrcode                           },
      { "question"                         , faIcon::question                         },
      { "questioncircle"                   , faIcon::questioncircle                   },
      { "questioncircleo"                  , faIcon::questioncircleo                  },
      { "quora"                            , faIcon::quora                            },
      { "quoteleft"                        , faIcon::quoteleft                        },
      { "quoteright"                       , faIcon::quoteright                       },
      { "ra"                               , faIcon::ra                               },
      { "random"                           , faIcon::random                           },
      { "ravelry"                          , faIcon::ravelry                          },
      { "rebel"                            , faIcon::rebel                            },
      { "recycle"                          , faIcon::recycle                          },
      { "reddit"                           , faIcon::reddit                           },
      { "redditalien"                      , faIcon::redditalien                      },
      { "redditsquare"                     , faIcon::redditsquare                     },
      { "refresh"                          , faIcon::refresh                          },
      { "registered"                       , faIcon::registered                       },
      { "remove"                           , faIcon::remove                           },
      { "renren"                           , faIcon::renren                           },
      { "reorder"                          , faIcon::reorder                          },
      { "repeat"                           , faIcon::repeat                           },
      { "reply"                            , faIcon::reply                            },
      { "replyall"                         , faIcon::replyall                         },
      { "resistance"                       , faIcon::resistance                       },
      { "retweet"                          , faIcon::retweet                          },
      { "rmb"                              , faIcon::rmb                              },
      { "road"                             , faIcon::road                             },
      { "rocket"                           , faIcon::rocket                           },
      { "rotateleft"                       , faIcon::rotateleft                       },
      { "rotateright"                      , faIcon::rotateright                      },
      { "rouble"                           , faIcon::rouble                           },
      { "rss"                              , faIcon::rss                              },
      { "rsssquare"                        , faIcon::rsssquare                        },
      { "rub"                              , faIcon::rub                              },
      { "ruble"                            , faIcon::ruble                            },
      { "rupee"                            , faIcon::rupee                            },
      { "s15"                              , faIcon::s15                              },
      { "safari"                           , faIcon::safari                           },
      { "save"                             , faIcon::save                             },
      { "scissors"                         , faIcon::scissors                         },
      { "scribd"                           , faIcon::scribd                           },
      { "search"                           , faIcon::search                           },
      { "searchminus"                      , faIcon::searchminus                      },
      { "searchplus"                       , faIcon::searchplus                       },
      { "sellsy"                           , faIcon::sellsy                           },
      { "send"                             , faIcon::send                             },
      { "sendo"                            , faIcon::sendo                            },
      { "server"                           , faIcon::server                           },
      { "share"                            , faIcon::share                            },
      { "sharealt"                         , faIcon::sharealt                         },
      { "sharealtsquare"                   , faIcon::sharealtsquare                   },
      { "sharesquare"                      , faIcon::sharesquare                      },
      { "sharesquareo"                     , faIcon::sharesquareo                     },
      { "shekel"                           , faIcon::shekel                           },
      { "sheqel"                           , faIcon::sheqel                           },
      { "shield"                           , faIcon::shield                           },
      { "ship"                             , faIcon::ship                             },
      { "shirtsinbulk"                     , faIcon::shirtsinbulk                     },
      { "shoppingbag"                      , faIcon::shoppingbag                      },
      { "shoppingbasket"                   , faIcon::shoppingbasket                   },
      { "shoppingcart"                     , faIcon::shoppingcart                     },
      { "shower"                           , faIcon::shower                           },
      { "signin"                           , faIcon::signin                           },
      { "signlanguage"                     , faIcon::signlanguage                     },
      { "signout"                          , faIcon::signout                          },
      { "signal"                           , faIcon::signal                           },
      { "signing"                          , faIcon::signing                          },
      { "simplybuilt"                      , faIcon::simplybuilt                      },
      { "sitemap"                          , faIcon::sitemap                          },
      { "skyatlas"                         , faIcon::skyatlas                         },
      { "skype"                            , faIcon::skype                            },
      { "slack"                            , faIcon::slack                            },
      { "sliders"                          , faIcon::sliders                          },
      { "slideshare"                       , faIcon::slideshare                       },
      { "smileo"                           , faIcon::smileo                           },
      { "snapchat"                         , faIcon::snapchat                         },
      { "snapchatghost"                    , faIcon::snapchatghost                    },
      { "snapchatsquare"                   , faIcon::snapchatsquare                   },
      { "snowflakeo"                       , faIcon::snowflakeo                       },
      { "soccerballo"                      , faIcon::soccerballo                      },
      { "sort"                             , faIcon::sort                             },
      { "sortalphaasc"                     , faIcon::sortalphaasc                     },
      { "sortalphadesc"                    , faIcon::sortalphadesc                    },
      { "sortamountasc"                    , faIcon::sortamountasc                    },
      { "sortamountdesc"                   , faIcon::sortamountdesc                   },
      { "sortasc"                          , faIcon::sortasc                          },
      { "sortdesc"                         , faIcon::sortdesc                         },
      { "sortdown"                         , faIcon::sortdown                         },
      { "sortnumericasc"                   , faIcon::sortnumericasc                   },
      { "sortnumericdesc"                  , faIcon::sortnumericdesc                  },
      { "sortup"                           , faIcon::sortup                           },
      { "soundcloud"                       , faIcon::soundcloud                       },
      { "spaceshuttle"                     , faIcon::spaceshuttle                     },
      { "spinner"                          , faIcon::spinner                          },
      { "spoon"                            , faIcon::spoon                            },
      { "spotify"                          , faIcon::spotify                          },
      { "square"                           , faIcon::square                           },
      { "squareo"                          , faIcon::squareo                          },
      { "stackexchange"                    , faIcon::stackexchange                    },
      { "stackoverflow"                    , faIcon::stackoverflow                    },
      { "star"                             , faIcon::star                             },
      { "starhalf"                         , faIcon::starhalf                         },
      { "starhalfempty"                    , faIcon::starhalfempty                    },
      { "starhalffull"                     , faIcon::starhalffull                     },
      { "starhalfo"                        , faIcon::starhalfo                        },
      { "staro"                            , faIcon::staro                            },
      { "steam"                            , faIcon::steam                            },
      { "steamsquare"                      , faIcon::steamsquare                      },
      { "stepbackward"                     , faIcon::stepbackward                     },
      { "stepforward"                      , faIcon::stepforward                      },
      { "stethoscope"                      , faIcon::stethoscope                      },
      { "stickynote"                       , faIcon::stickynote                       },
      { "stickynoteo"                      , faIcon::stickynoteo                      },
      { "stop"                             , faIcon::stop                             },
      { "stopcircle"                       , faIcon::stopcircle                       },
      { "stopcircleo"                      , faIcon::stopcircleo                      },
      { "streetview"                       , faIcon::streetview                       },
      { "strikethrough"                    , faIcon::strikethrough                    },
      { "stumbleupon"                      , faIcon::stumbleupon                      },
      { "stumbleuponcircle"                , faIcon::stumbleuponcircle                },
      { "subscript"                        , faIcon::subscript                        },
      { "subway"                           , faIcon::subway                           },
      { "suitcase"                         , faIcon::suitcase                         },
      { "suno"                             , faIcon::suno                             },
      { "superpowers"                      , faIcon::superpowers                      },
      { "superscript"                      , faIcon::superscript                      },
      { "support"                          , faIcon::support                          },
      { "table"                            , faIcon::table                            },
      { "tablet"                           , faIcon::tablet                           },
      { "tachometer"                       , faIcon::tachometer                       },
      { "tag"                              , faIcon::tag                              },
      { "tags"                             , faIcon::tags                             },
      { "tasks"                            , faIcon::tasks                            },
      { "taxi"                             , faIcon::taxi                             },
      { "telegram"                         , faIcon::telegram                         },
      { "television"                       , faIcon::television                       },
      { "tencentweibo"                     , faIcon::tencentweibo                     },
      { "terminal"                         , faIcon::terminal                         },
      { "textheight"                       , faIcon::textheight                       },
      { "textwidth"                        , faIcon::textwidth                        },
      { "th"                               , faIcon::th                               },
      { "thlarge"                          , faIcon::thlarge                          },
      { "thlist"                           , faIcon::thlist                           },
      { "themeisle"                        , faIcon::themeisle                        },
      { "thermometer"                      , faIcon::thermometer                      },
      { "thermometer0"                     , faIcon::thermometer0                     },
      { "thermometer1"                     , faIcon::thermometer1                     },
      { "thermometer2"                     , faIcon::thermometer2                     },
      { "thermometer3"                     , faIcon::thermometer3                     },
      { "thermometer4"                     , faIcon::thermometer4                     },
      { "thermometerempty"                 , faIcon::thermometerempty                 },
      { "thermometerfull"                  , faIcon::thermometerfull                  },
      { "thermometerhalf"                  , faIcon::thermometerhalf                  },
      { "thermometerquarter"               , faIcon::thermometerquarter               },
      { "thermometerthreequarters"         , faIcon::thermometerthreequarters         },
      { "thumbtack"                        , faIcon::thumbtack                        },
      { "thumbsdown"                       , faIcon::thumbsdown                       },
      { "thumbsodown"                      , faIcon::thumbsodown                      },
      { "thumbsoup"                        , faIcon::thumbsoup                        },
      { "thumbsup"                         , faIcon::thumbsup                         },
      { "ticket"                           , faIcon::ticket                           },
      { "times"                            , faIcon::times                            },
      { "timescircle"                      , faIcon::timescircle                      },
      { "timescircleo"                     , faIcon::timescircleo                     },
      { "timesrectangle"                   , faIcon::timesrectangle                   },
      { "timesrectangleo"                  , faIcon::timesrectangleo                  },
      { "tint"                             , faIcon::tint                             },
      { "toggledown"                       , faIcon::toggledown                       },
      { "toggleleft"                       , faIcon::toggleleft                       },
      { "toggleoff"                        , faIcon::toggleoff                        },
      { "toggleon"                         , faIcon::toggleon                         },
      { "toggleright"                      , faIcon::toggleright                      },
      { "toggleup"                         , faIcon::toggleup                         },
      { "trademark"                        , faIcon::trademark                        },
      { "train"                            , faIcon::train                            },
      { "transgender"                      , faIcon::transgender                      },
      { "transgenderalt"                   , faIcon::transgenderalt                   },
      { "trash"                            , faIcon::trash                            },
      { "trasho"                           , faIcon::trasho                           },
      { "tree"                             , faIcon::tree                             },
      { "trello"                           , faIcon::trello                           },
      { "tripadvisor"                      , faIcon::tripadvisor                      },
      { "trophy"                           , faIcon::trophy                           },
      { "truck"                            , faIcon::truck                            },
      { "fa_try"                           , faIcon::fa_try                           },
      { "tty"                              , faIcon::tty                              },
      { "tumblr"                           , faIcon::tumblr                           },
      { "tumblrsquare"                     , faIcon::tumblrsquare                     },
      { "turkishlira"                      , faIcon::turkishlira                      },
      { "tv"                               , faIcon::tv                               },
      { "twitch"                           , faIcon::twitch                           },
      { "twitter"                          , faIcon::twitter                          },
      { "twittersquare"                    , faIcon::twittersquare                    },
      { "umbrella"                         , faIcon::umbrella                         },
      { "underline"                        , faIcon::underline                        },
      { "undo"                             , faIcon::undo                             },
      { "universalaccess"                  , faIcon::universalaccess                  },
      { "university"                       , faIcon::university                       },
      { "unlink"                           , faIcon::unlink                           },
      { "unlock"                           , faIcon::unlock                           },
      { "unlockalt"                        , faIcon::unlockalt                        },
      { "unsorted"                         , faIcon::unsorted                         },
      { "upload"                           , faIcon::upload                           },
      { "usb"                              , faIcon::usb                              },
      { "usd"                              , faIcon::usd                              },
      { "user"                             , faIcon::user                             },
      { "usercircle"                       , faIcon::usercircle                       },
      { "usercircleo"                      , faIcon::usercircleo                      },
      { "usermd"                           , faIcon::usermd                           },
      { "usero"                            , faIcon::usero                            },
      { "userplus"                         , faIcon::userplus                         },
      { "usersecret"                       , faIcon::usersecret                       },
      { "usertimes"                        , faIcon::usertimes                        },
      { "users"                            , faIcon::users                            },
      { "vcard"                            , faIcon::vcard                            },
      { "vcardo"                           , faIcon::vcardo                           },
      { "venus"                            , faIcon::venus                            },
      { "venusdouble"                      , faIcon::venusdouble                      },
      { "venusmars"                        , faIcon::venusmars                        },
      { "viacoin"                          , faIcon::viacoin                          },
      { "viadeo"                           , faIcon::viadeo                           },
      { "viadeosquare"                     , faIcon::viadeosquare                     },
      { "videocamera"                      , faIcon::videocamera                      },
      { "vimeo"                            , faIcon::vimeo                            },
      { "vimeosquare"                      , faIcon::vimeosquare                      },
      { "vine"                             , faIcon::vine                             },
      { "vk"                               , faIcon::vk                               },
      { "volumecontrolphone"               , faIcon::volumecontrolphone               },
      { "volumedown"                       , faIcon::volumedown                       },
      { "volumeoff"                        , faIcon::volumeoff                        },
      { "volumeup"                         , faIcon::volumeup                         },
      { "warning"                          , faIcon::warning                          },
      { "wechat"                           , faIcon::wechat                           },
      { "weibo"                            , faIcon::weibo                            },
      { "weixin"                           , faIcon::weixin                           },
      { "whatsapp"                         , faIcon::whatsapp                         },
      { "wheelchair"                       , faIcon::wheelchair                       },
      { "wheelchairalt"                    , faIcon::wheelchairalt                    },
      { "wifi"                             , faIcon::wifi                             },
      { "wikipediaw"                       , faIcon::wikipediaw                       },
      { "windowclose"                      , faIcon::windowclose                      },
      { "windowcloseo"                     , faIcon::windowcloseo                     },
      { "windowmaximize"                   , faIcon::windowmaximize                   },
      { "windowminimize"                   , faIcon::windowminimize                   },
      { "windowrestore"                    , faIcon::windowrestore                    },
      { "windows"                          , faIcon::windows                          },
      { "won"                              , faIcon::won                              },
      { "wordpress"                        , faIcon::wordpress                        },
      { "wpbeginner"                       , faIcon::wpbeginner                       },
      { "wpexplorer"                       , faIcon::wpexplorer                       },
      { "wpforms"                          , faIcon::wpforms                          },
      { "wrench"                           , faIcon::wrench                           },
      { "xing"                             , faIcon::xing                             },
      { "xingsquare"                       , faIcon::xingsquare                       },
      { "ycombinator"                      , faIcon::ycombinator                      },
      { "ycombinatorsquare"                , faIcon::ycombinatorsquare                },
      { "yahoo"                            , faIcon::yahoo                            },
      { "yc"                               , faIcon::yc                               },
      { "ycsquare"                         , faIcon::ycsquare                         },
      { "yelp"                             , faIcon::yelp                             },
      { "yen"                              , faIcon::yen                              },
      { "yoast"                            , faIcon::yoast                            },
      { "youtube"                          , faIcon::youtube                          },
      { "youtubeplay"                      , faIcon::youtubeplay                      },
      { "youtubesquare"                    , faIcon::youtubesquare                    }
};


//----------------------------------------------------------------------------------------------------------------------------
QString AppFontIcon::strFontName;
QVariantMap AppFontIcon::iconStyles;
QHash<QString, int> AppFontIcon::mapNameCode;


bool AppFontIcon::initFontAwesome()
{
    static int fontAwesomeFontId = -1;
    if( fontAwesomeFontId < 0 ) 
	{
        QFile res(":/fonts/iconfont.ttf");
        if(!res.open(QIODevice::ReadOnly)) 
		{
            qDebug() << "Font awesome font could not be loaded!";
            return false;
        }
        QByteArray fontData( res.readAll() );
        res.close();

        fontAwesomeFontId = QFontDatabase::addApplicationFontFromData(fontData);
    }

    QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(fontAwesomeFontId);
    if( !loadedFontFamilies.empty() ) 
	{
        strFontName= loadedFontFamilies.at(0);
    } 
	else 
	{
        qDebug() << "Font awesome font is empty?!";
        fontAwesomeFontId = -1;
        return false;
    }

	mapNameCode.clear();
    for (unsigned i = 0; i < sizeof(faNameIconArray)/sizeof(stFaNameIcon); ++i) 
	{
		mapNameCode.insert(faNameIconArray[i].name, faNameIconArray[i].icon);
    }

	setDefaultBlackStyle();
    return true;
}

void AppFontIcon::setDefaultBlackStyle()
{
	setDefaultStyle("color", QColor(50, 50, 50));
	setDefaultStyle("color-disabled", QColor(70, 70, 70, 60));
	setDefaultStyle("color-active", QColor(10, 10, 10));
	setDefaultStyle("color-selected", QColor(10, 10, 10));
	setDefaultStyle("background-color-on", QColor(190,190,190));
	setDefaultStyle("background-color-off", QColor(190, 190, 190));

	setDefaultStyle("scale-factor", 0.9);

	setDefaultStyle("text", QVariant());
	setDefaultStyle("text-disabled", QVariant());
	setDefaultStyle("text-active", QVariant());
	setDefaultStyle("text-selected", QVariant());
}

void AppFontIcon::setDefaultStyle(const QString& name, const QVariant& value)
{
    iconStyles.insert( name, value );
}

QFont AppFontIcon::getFont(int size)
{
	if (strFontName.isEmpty())
		initFontAwesome();

	QFont font(strFontName);
	font.setPixelSize(size);
	return font;
}

static QVariantMap mergeOptions(const QVariantMap& defaults, const QVariantMap& override)
{
    QVariantMap result= defaults;
    if(!override.isEmpty()) 
	{
        QMapIterator<QString,QVariant> itr(override);
        while(itr.hasNext()) 
		{
            itr.next();
            result.insert(itr.key(), itr.value());
        }
    }
    return result;
}

QIcon AppFontIcon::getIcon(int character, const QVariantMap &options)
{
	if (strFontName.isEmpty())
		initFontAwesome();

    QVariantMap optionMap = mergeOptions( iconStyles, options );
    optionMap.insert("text", QString( QChar(static_cast<int>(character)) ) );
    return getIcon(optionMap);
}

QIcon AppFontIcon::getIcon(const QString& name, const QVariantMap& options)
{
	if (strFontName.isEmpty())
		initFontAwesome();

    if(mapNameCode.contains(name)) 
	{
        return getIcon(mapNameCode.value(name), options);
    }

    return QIcon();
}

QIcon AppFontIcon::getIcon(const QVariantMap& optionMap )
{
	if (strFontName.isEmpty())
		initFontAwesome();

    //QScopedPointer<AppFontPainterIconEngine> engine(new AppFontPainterIconEngine(optionMap));

	AppFontPainterIconEngine * engine = new AppFontPainterIconEngine(optionMap);
    return QIcon(engine);
}

//----------------------------------------------------------------------------------------------------------------------------
AppFontPainterIconEngine::AppFontPainterIconEngine(const QVariantMap & options)
{
	optionMap = options;
}

AppFontPainterIconEngine::~AppFontPainterIconEngine()
{

}

AppFontPainterIconEngine* AppFontPainterIconEngine::clone() const
{
	return new AppFontPainterIconEngine(optionMap);
}

void AppFontPainterIconEngine::paint(QPainter* painter, const QRect& rect, QIcon::Mode mode, QIcon::State state)
{
	painter->save();

	QPointer<QObject> qanim = qvariant_cast<QObject*>(optionMap.value("anim"));
	QPointer<AppFontIconAnimation> anim = qobject_cast<AppFontIconAnimation*>(qanim);
	if (anim)
	{
		anim->setup(*painter, rect);
	}

	// set the correct color
	QColor color = optionMap.value("color").value<QColor>();
	QString text = optionMap.value("text").toString();

	if (mode == QIcon::Disabled)
	{
		color = optionMap.value("color-disabled").value<QColor>();
		QVariant alt = optionMap.value("text-disabled");
		if (alt.isValid())
		{
			text = alt.toString();
		}
	}
	else if (mode == QIcon::Active)
	{
		color = optionMap.value("color-active").value<QColor>();
		QVariant alt = optionMap.value("text-active");
		if (alt.isValid())
		{
			text = alt.toString();
		}
	}
	else if (mode == QIcon::Selected)
	{
		color = optionMap.value("color-selected").value<QColor>();
		QVariant alt = optionMap.value("text-selected");
		if (alt.isValid())
		{
			text = alt.toString();
		}
	}

	QColor bkColor;
	if (state == QIcon::On)
	{
		bkColor = optionMap.value("background-color-on").value<QColor>();
	}
	else
	{
		bkColor = optionMap.value("background-color-off").value<QColor>();
	}

	painter->setBrush(QBrush(bkColor));
	painter->drawRect(rect);

	painter->setPen(color);

	// add some 'padding' around the icon
	int drawSize = qRound(rect.height() * optionMap.value("scale-factor").toFloat());

	painter->setFont(AppFontIcon::getFont(drawSize));
	painter->drawText(rect, text, QTextOption(Qt::AlignCenter | Qt::AlignVCenter));
	painter->restore();
}

QPixmap AppFontPainterIconEngine::pixmap(const QSize& size, QIcon::Mode mode, QIcon::State state)
{
	QPixmap pm(size);
	pm.fill(Qt::transparent);
	{
		QPainter p(&pm);
		paint(&p, QRect(QPoint(0, 0), size), mode, state);
	}
	return pm;
}
