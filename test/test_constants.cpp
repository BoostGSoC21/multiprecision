// Copyright John Maddock 2012.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifdef _MSC_VER
#define _SCL_SECURE_NO_WARNINGS
#endif

#if !defined(TEST_MPF_50) && !defined(TEST_CPP_DEC_FLOAT) && !defined(TEST_MPFR_50) && !defined(TEST_QD)
#define TEST_MPF_50
#define TEST_CPP_DEC_FLOAT
#define TEST_MPFR_50
#define TEST_QD

#ifdef _MSC_VER
#pragma message("CAUTION!!: No backend type specified so testing everything.... this will take some time!!")
#endif
#ifdef __GNUC__
#pragma warning "CAUTION!!: No backend type specified so testing everything.... this will take some time!!"
#endif

#endif

#if defined(TEST_MPF_50)
#include <boost/multiprecision/gmp.hpp>
#endif
#if defined(TEST_MPFR_50)
#include <boost/multiprecision/mpfr.hpp>
#endif
#ifdef TEST_CPP_DEC_FLOAT
#include <boost/multiprecision/cpp_dec_float.hpp>
#endif
#ifdef TEST_QD
#include <boost/multiprecision/quad_double.hpp>
#endif

#include "test.hpp"

static const char* ln2 =
    "0.693147180559945309417232121458176568075500134360255254120680009493393621969694"
    "71560586332699641868754200148102057068573368552023575813055703267075163507596193"
    "07275708283714351903070386238916734711233501153644979552391204751726815749320651"
    "55524734139525882950453007095326366642654104239157814952043740430385500801944170"
    "64167151864471283996817178454695702627163106454615025720740248163777338963855069"
    "52606683411372738737229289564935470257626520988596932019650585547647033067936544"
    "32547632744951250406069438147104689946506220167720424524529612687946546193165174"
    "68139267250410380254625965686914419287160829380317271436778265487756648508567407"
    "76484514644399404614226031930967354025744460703080960850474866385231381816767514"
    "38667476647890881437141985494231519973548803751658612753529166100071053558249879"
    "41472950929311389715599820565439287170007218085761025236889213244971389320378439"
    "35308877482597017155910708823683627589842589185353024363421436706118923678919237"
    "23146723217205340164925687274778234453534764811494186423867767744060695626573796"
    "00867076257199184734022651462837904883062033061144630073719489002743643965002580"
    "93651944304119115060809487930678651588709006052034684297361938412896525565396860"
    "22194122924207574321757489097706752687115817051137009158942665478595964890653058"
    "46025866838294002283300538207400567705304678700184162404418833232798386349001563"
    "12188956065055315127219939833203075140842609147900126516824344389357247278820548"
    "62715527418772430024897945401961872339808608316648114909306675193393128904316413"
    "70681397776498176974868903887789991296503619270710889264105230924783917373501229"
    "84242049956893599220660220465494151061391878857442455775102068370308666194808964"
    "12186807790208181588580001688115973056186676199187395200766719214592236720602539"
    "59543654165531129517598994005600036651356756905124592682574394648316833262490180"
    "38242408242314523061409638057007025513877026817851630690255137032340538021450190"
    "15374029509942262995779647427138157363801729873940704242179972266962979939312706"
    "93574724049338653087975872169964512944649188377115670167859880498183889678413493"
    "83140140731664727653276359192335112333893387095132090592721854713289754707978913"
    "84445466676192702885533423429899321803769154973340267546758873236778342916191810"
    "43011609169526554785973289176354555674286387746398710191243175425588830120677921"
    "02803412068797591430812833072303008834947057924965910058600123415617574132724659"
    "43068435465211135021544341539955381856522750221424566440006276183303206472725721"
    "97515290827856842132079598863896727711955221881904660395700977470651261950527893"
    "22960889314056254334425523920620303439417773579455921259019925591148440242390125"
    "54259003129537051922061506434583787873002035414421785758013236451660709914383145"
    "00498589668857722214865288216941812704886075897220321666312837832915676307498729"
    "85746389282693735098407780493950049339987626475507031622161390348452994249172483"
    "73406136622638349368111684167056925214751383930638455371862687797328895558871634"
    "429756244755392366369488877823890174981027";
static const char* pi =
    "3.141592653589793238462643383279502884197169399375105820974944592307816406286208"
    "99862803482534211706798214808651328230664709384460955058223172535940812848111745"
    "02841027019385211055596446229489549303819644288109756659334461284756482337867831"
    "65271201909145648566923460348610454326648213393607260249141273724587006606315588"
    "17488152092096282925409171536436789259036001133053054882046652138414695194151160"
    "94330572703657595919530921861173819326117931051185480744623799627495673518857527"
    "24891227938183011949129833673362440656643086021394946395224737190702179860943702"
    "77053921717629317675238467481846766940513200056812714526356082778577134275778960"
    "91736371787214684409012249534301465495853710507922796892589235420199561121290219"
    "60864034418159813629774771309960518707211349999998372978049951059731732816096318"
    "59502445945534690830264252230825334468503526193118817101000313783875288658753320"
    "83814206171776691473035982534904287554687311595628638823537875937519577818577805"
    "32171226806613001927876611195909216420198938095257201065485863278865936153381827"
    "96823030195203530185296899577362259941389124972177528347913151557485724245415069"
    "59508295331168617278558890750983817546374649393192550604009277016711390098488240"
    "12858361603563707660104710181942955596198946767837449448255379774726847104047534"
    "64620804668425906949129331367702898915210475216205696602405803815019351125338243"
    "00355876402474964732639141992726042699227967823547816360093417216412199245863150"
    "30286182974555706749838505494588586926995690927210797509302955321165344987202755"
    "96023648066549911988183479775356636980742654252786255181841757467289097777279380"
    "00816470600161452491921732172147723501414419735685481613611573525521334757418494"
    "68438523323907394143334547762416862518983569485562099219222184272550254256887671"
    "79049460165346680498862723279178608578438382796797668145410095388378636095068006"
    "42251252051173929848960841284886269456042419652850222106611863067442786220391949"
    "45047123713786960956364371917287467764657573962413890865832645995813390478027590"
    "09946576407895126946839835259570982582262052248940772671947826848260147699090264"
    "01363944374553050682034962524517493996514314298091906592509372216964615157098583"
    "87410597885959772975498930161753928468138268683868942774155991855925245953959431"
    "04997252468084598727364469584865383673622262609912460805124388439045124413654976"
    "27807977156914359977001296160894416948685558484063534220722258284886481584560285"
    "06016842739452267467678895252138522549954666727823986456596116354886230577456498"
    "03559363456817432411251507606947945109659609402522887971089314566913686722874894"
    "05601015033086179286809208747609178249385890097149096759852613655497818931297848"
    "21682998948722658804857564014270477555132379641451523746234364542858444795265867"
    "82105114135473573952311342716610213596953623144295248493718711014576540359027993"
    "44037420073105785390621983874478084784896833214457138687519435064302184531910484"
    "81005370614680674919278191197939952061419663428754440643745123718192179998391015"
    "91956181467514269123974894090718649423196";
static const char* e =
    "2.718281828459045235360287471352662497757247093699959574966967627724076630353547"
    "59457138217852516642742746639193200305992181741359662904357290033429526059563073"
    "81323286279434907632338298807531952510190115738341879307021540891499348841675092"
    "44761460668082264800168477411853742345442437107539077744992069551702761838606261"
    "33138458300075204493382656029760673711320070932870912744374704723069697720931014"
    "16928368190255151086574637721112523897844250569536967707854499699679468644549059"
    "87931636889230098793127736178215424999229576351482208269895193668033182528869398"
    "49646510582093923982948879332036250944311730123819706841614039701983767932068328"
    "23764648042953118023287825098194558153017567173613320698112509961818815930416903"
    "51598888519345807273866738589422879228499892086805825749279610484198444363463244"
    "96848756023362482704197862320900216099023530436994184914631409343173814364054625"
    "31520961836908887070167683964243781405927145635490613031072085103837505101157477"
    "04171898610687396965521267154688957035035402123407849819334321068170121005627880"
    "23519303322474501585390473041995777709350366041699732972508868769664035557071622"
    "68447162560798826517871341951246652010305921236677194325278675398558944896970964"
    "09754591856956380236370162112047742722836489613422516445078182442352948636372141"
    "74023889344124796357437026375529444833799801612549227850925778256209262264832627"
    "79333865664816277251640191059004916449982893150566047258027786318641551956532442"
    "58698294695930801915298721172556347546396447910145904090586298496791287406870504"
    "89585867174798546677575732056812884592054133405392200011378630094556068816674001"
    "69842055804033637953764520304024322566135278369511778838638744396625322498506549"
    "95886234281899707733276171783928034946501434558897071942586398772754710962953741"
    "52111513683506275260232648472870392076431005958411661205452970302364725492966693"
    "81151373227536450988890313602057248176585118063036442812314965507047510254465011"
    "72721155519486685080036853228183152196003735625279449515828418829478761085263981"
    "39559900673764829224437528718462457803619298197139914756448826260390338144182326"
    "25150974827987779964373089970388867782271383605772978824125611907176639465070633"
    "04527954661855096666185664709711344474016070462621568071748187784437143698821855"
    "96709591025968620023537185887485696522000503117343920732113908032936344797273559"
    "55277349071783793421637012050054513263835440001863239914907054797780566978533580"
    "48966906295119432473099587655236812859041383241160722602998330535370876138939639"
    "17795745401613722361878936526053815584158718692553860616477983402543512843961294"
    "60352913325942794904337299085731580290958631382683291477116396337092400316894586"
    "36060645845925126994655724839186564209752685082307544254599376917041977780085362"
    "73094171016343490769642372229435236612557250881477922315197477806056967253801718"
    "07763603462459278778465850656050780844211529697521890874019660906651803516501792"
    "50461950136658543663271254963990854914420001457476081930221206602433009641270489"
    "43903971771951806990869986066365832322787";

template <class T>
inline bool is_mpfr(const T&)
{
   return false;
}
#if defined(TEST_MPFR_50)
template <unsigned N, boost::multiprecision::expression_template_option ET>
inline bool is_mpfr(const boost::multiprecision::number<boost::multiprecision::mpfr_float_backend<N>, ET>&)
{
   return true;
}
#endif

template <class T>
void test()
{
   typedef typename T::backend_type backend_type;
   T                                num, expect;
   num.backend() = boost::multiprecision::default_ops::get_constant_pi<backend_type>();
   expect        = static_cast<T>(pi);
   BOOST_CHECK_CLOSE_FRACTION(num, expect, std::numeric_limits<T>::epsilon() * (is_mpfr(num) ? 1200 : 2));
   num.backend() = boost::multiprecision::default_ops::get_constant_ln2<backend_type>();
   expect        = static_cast<T>(ln2);
   BOOST_CHECK_CLOSE_FRACTION(num, expect, std::numeric_limits<T>::epsilon() * (is_mpfr(num) ? 30 : 1));
   num.backend() = boost::multiprecision::default_ops::get_constant_e<backend_type>();
   expect        = static_cast<T>(e);
   BOOST_CHECK_CLOSE_FRACTION(num, expect, std::numeric_limits<T>::epsilon() * (is_mpfr(num) ? 2 : 1));
}

int main()
{
#ifdef TEST_MPFR_50
   test<boost::multiprecision::number<boost::multiprecision::mpfr_float_backend<2000> > >();
#endif
#ifdef TEST_CPP_DEC_FLOAT
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<2000> > >();
#endif
#ifdef TEST_MPF_50
   test<boost::multiprecision::number<boost::multiprecision::gmp_float<2000> > >();
#endif
#ifdef TEST_QD
   test<boost::multiprecision::quad_double>();
#endif
   return boost::report_errors();
}
