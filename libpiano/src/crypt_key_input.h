/*
Copyright (c) 2008-2010
	Lars-Dominik Braun <PromyLOPh@lavabit.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef _CRYPT_KEY_INPUT_H
#define _CRYPT_KEY_INPUT_H

#include <stdint.h>

/* decryption key for last 48 bytes of audio urls
 * search for rpc.input in the decompiled pandora actionscript
 */

const unsigned int in_key_n = 16;

static const uint32_t in_key_p [16 + 2] = {
		0x50E2A8D4L, 0x103290CCL, 0x2BCFDB20L, 0xEC665FF6L,
		0xA6521A84L, 0x536F33BFL, 0xA2229197L, 0x1B797EF7L,
		0x646C1CB4L, 0xCDDE464AL, 0xCA864B25L, 0x20D6E3F7L,
		0xB581B8C7L, 0x62E70576L, 0xE14C7649L, 0xB71A3F19L,
		0xCCEE1164L, 0xF7A94CE1L,
		};

static const uint32_t in_key_s [4][256] = {{
		0x6741D820L, 0x61599D6DL, 0x8513F3BFL, 0xF7A30985L,
		0x88DC9FFFL, 0xECB90622L, 0x48C3CEC2L, 0xB1C96B9FL,
		0x5E0CAD63L, 0x49BD8C2DL, 0x8875BA79L, 0x5C91F805L,
		0x06C56433L, 0xDA2D45BDL, 0xF234A5B6L, 0xE0E7804BL,
		0x27A8A4D6L, 0xA26F926CL, 0xC3C7256BL, 0x3684A81FL,
		0x71C805CAL, 0xA70E162FL, 0xDB4AD7B5L, 0x8D80E13FL,
		0x302026D8L, 0x3F4B5CC7L, 0x0E3D1704L, 0xF97461D2L,
		0x747CA5B6L, 0xCC558E08L, 0x32C1DD57L, 0xAF8197DCL,
		0x98278B1FL, 0x74B5D610L, 0x805D61B7L, 0x6DACC6DDL,
		0x0D5E8E95L, 0x49A7C8BAL, 0x40C28482L, 0xF27175D0L,
		0x345FD672L, 0x1F4A851FL, 0x697C8164L, 0xB260A8E5L,
		0x3EEC09D7L, 0x586D440EL, 0xFEA50356L, 0x6AA176C4L,
		0xD2B950E9L, 0xB63A73F7L, 0x9D834CA6L, 0xEA7B5839L,
		0x963559A9L, 0x02B91B6CL, 0x03E4EF42L, 0x3B10FD7FL,
		0xF98557A0L, 0x63DAACD0L, 0xE2FBDA2DL, 0xC2B332A7L,
		0x34F9F6EDL, 0xA5D10A60L, 0x79D79086L, 0xBDA64EEBL,
		0xA6867356L, 0xCF878D4CL, 0x486B3CFCL, 0x51C0BD5FL,
		0x73383396L, 0xE2AC907CL, 0xFE91DD09L, 0x9B3D72E6L,
		0x557B1E51L, 0xB9763F9BL, 0xAEA2A746L, 0x7CAF79A7L,
		0xB6044A7BL, 0xC58195D8L, 0x2C848DD8L, 0x72E845C1L,
		0x6FF900A4L, 0x4645AB96L, 0xDA3D58D4L, 0x9253382CL,
		0xD50FDB0BL, 0xA522558BL, 0xE782F76CL, 0x1A41A9A4L,
		0xBD6300DDL, 0xF38A2CC7L, 0x0D9C5079L, 0xEA4191B4L,
		0xF5806863L, 0xCF6D271FL, 0x01B7320CL, 0xB93D1325L,
		0xC58DA1BEL, 0x70CD8577L, 0x3C1E0796L, 0x17D7AE8AL,
		0x12C7E2F3L, 0x240F0D4DL, 0x0EDC40B6L, 0x02447A9CL,
		0x643CCCEEL, 0x12E7476AL, 0xFF6620FEL, 0xDD581F89L,
		0x9849D29AL, 0xA8B8D2F4L, 0xC1233FF1L, 0x2B0F785AL,
		0x9AFB6D15L, 0x3BF89716L, 0x85105F6CL, 0xA46CC28DL,
		0x65B197A8L, 0xC40ACC08L, 0xDA0CA7A3L, 0x112BCF13L,
		0x81287948L, 0x42934B76L, 0x7DE2E016L, 0x3C106F13L,
		0x5E6CFFB7L, 0x34DAF94EL, 0x032D1BB6L, 0x97741F3CL,
		0x9FA0AFD1L, 0x8BED73A9L, 0xAAB5011AL, 0x3D02C77CL,
		0xD43FF261L, 0x5BC72505L, 0xA7976F41L, 0x4D87398DL,
		0x03C8B977L, 0x96334C23L, 0x1ECFD285L, 0xB8D14F76L,
		0x5EF4FCFDL, 0xD6218032L, 0x7ED772F5L, 0x958FF519L,
		0x244DFABBL, 0x0BBC5EDDL, 0xCD2DF778L, 0x667F3C3BL,
		0x4A638665L, 0x5588FD81L, 0x3D0DF17DL, 0x3871973CL,
		0xDF68E330L, 0x8A04E4FEL, 0x7D6A6DC0L, 0x2D85D433L,
		0x3B740C18L, 0xAE3EB3FBL, 0x1D95793AL, 0x29E2156EL,
		0x6E015902L, 0x10DCF520L, 0x93225144L, 0x3BB17F29L,
		0xE79091C5L, 0x439E1755L, 0x4229B6DCL, 0xEE366F54L,
		0x73EC4428L, 0xD0415325L, 0x583EFC6DL, 0x7CF58E00L,
		0x12E17B5EL, 0xA7BB50BEL, 0x3F274960L, 0x334DDB37L,
		0xF05CC54AL, 0x6DF249B2L, 0x00561B82L, 0x925B78B2L,
		0x0C54A34AL, 0x77CE1514L, 0x5A41B671L, 0x27ED5273L,
		0x33302D43L, 0x46C8E20AL, 0x71E0939BL, 0x58B79033L,
		0x3BAA1B71L, 0x1BEE36D3L, 0xAA6B74B1L, 0x973EA0E6L,
		0x9EBC480FL, 0x8F304003L, 0x90305277L, 0x339DD096L,
		0x570CDF36L, 0x5E1422C7L, 0xFD4DFA77L, 0xA7E4BD60L,
		0x444DA8C0L, 0xB97026D2L, 0x6836E205L, 0xBB81A25AL,
		0xD0BFCA10L, 0xC768CC6AL, 0xF532AD01L, 0x0E7A4E70L,
		0xBE391242L, 0x93061C8BL, 0x4A227558L, 0x1156A957L,
		0x9EEFDCE2L, 0xD5728062L, 0xFC25DE98L, 0x25A899FCL,
		0x727754CAL, 0x91CB098BL, 0xE7610A22L, 0xC60879C0L,
		0x7B9EE54EL, 0x7B256444L, 0xBD08D9E6L, 0xB79E8EFDL,
		0xAAAD6184L, 0x7E509018L, 0x0BADA391L, 0xC600AF03L,
		0xC92096FFL, 0xF44E2008L, 0xE4A71B8EL, 0xCD33A7BEL,
		0x0BB1109CL, 0x2A3BA5FBL, 0xAE7163F1L, 0xD988B80BL,
		0x64CB7628L, 0x43CD0A4DL, 0x7FD13B59L, 0x5574D473L,
		0x3A0900A7L, 0xC35F6D75L, 0x5FFB13BEL, 0x784A0061L,
		0x7881E5CFL, 0xD65F7B1FL, 0xD9D98329L, 0x7A267038L,
		0xCB60D0EBL, 0x5E04323AL, 0xF20494EAL, 0x6247C11AL,
		0x85D1DC30L, 0x8AC88FE0L, 0x90C11871L, 0x7BA8F473L,
		}, {
		0xA3F71745L, 0xE4A3D5BEL, 0x1E9EBA3CL, 0x596FBCFEL,
		0x9F16B71CL, 0x61B631C5L, 0x80BD9680L, 0x4C534080L,
		0xA7C36E7DL, 0xCC539FB9L, 0x6462452CL, 0xBAD63850L,
		0x7B1EA843L, 0xA726F757L, 0x0C76B9AFL, 0xFE89E628L,
		0xDDE971D0L, 0x72C4773BL, 0xF968671AL, 0x479DFF15L,
		0x71FCD129L, 0x6E423698L, 0x7D164AC9L, 0x05775F88L,
		0x40BAA21CL, 0x54983AD9L, 0xE58A79CDL, 0x8081DE2CL,
		0xBBCF089FL, 0xC22F92E4L, 0x644F37EEL, 0xE6C2F895L,
		0x36156D6DL, 0x007BA6DBL, 0x62893E96L, 0xC43C2DD4L,
		0xB458767AL, 0xF7655BE2L, 0x44EC47BBL, 0xA408593CL,
		0x692ED547L, 0xB5212EBCL, 0x26842D78L, 0x1593E052L,
		0x31D3BAAAL, 0x65C26C32L, 0x3718EC84L, 0xBB49E8D2L,
		0xA871F999L, 0x8848EE63L, 0xE957B9C6L, 0xB75ADB60L,
		0x83AC9603L, 0xE54738A4L, 0xB9D08C05L, 0x7431BDA1L,
		0x9F29AA05L, 0x02EC4676L, 0x6B2E2DF6L, 0xB3692071L,
		0x2F394CF2L, 0x21057E7EL, 0xAFA24D83L, 0x0FFFC6D8L,
		0xAC5DB4ACL, 0x3BB1146DL, 0x34EE3669L, 0x42B6255AL,
		0x72B299AEL, 0x013A1064L, 0x6EAF685EL, 0x70C2567FL,
		0x4255AF73L, 0xB8C785B7L, 0x97722E31L, 0x06EE7057L,
		0xB38B4E40L, 0x9F82DC49L, 0x18EF6B80L, 0x89A5A4E6L,
		0x288BF724L, 0x47BC9E76L, 0x2B156F37L, 0xDFA3B9EBL,
		0x7BD09413L, 0xF16345F4L, 0xA01C5042L, 0xAF9E65D7L,
		0x6C953DA2L, 0xE3DCABC0L, 0xC53B64C4L, 0x5F3F3815L,
		0xB352DD67L, 0x7EFD50B8L, 0x82DFF301L, 0x93537070L,
		0x35BC5264L, 0x8234DD52L, 0xF8F7AE32L, 0x39D60BFAL,
		0x10EA978BL, 0xBCA06773L, 0x0EB60F22L, 0x4AB08AB0L,
		0xACEAF1CBL, 0x487746B8L, 0x6AE6A895L, 0xFA301CA9L,
		0xE51A87C5L, 0x25845BC9L, 0xDE9BE899L, 0xF8EB2AD2L,
		0x03AA322BL, 0x51AB8520L, 0xE23ED118L, 0x099F981AL,
		0x85B7CA73L, 0xB3336764L, 0x2D04E399L, 0x670C78BBL,
		0xD6816896L, 0xECAE0B46L, 0x932B8821L, 0x52AC3092L,
		0xE00FE817L, 0xDD1F63C5L, 0x0ACED210L, 0x8264432BL,
		0x7D4E7BAFL, 0x9A7A4984L, 0x4BD7ACFDL, 0x3895C28CL,
		0x6709466FL, 0xB182C19FL, 0x8EDC8894L, 0x38A1B878L,
		0xFCA6BF04L, 0x6541583AL, 0xC8CD8C2EL, 0xA36CDEB8L,
		0x2FD21E07L, 0xE593A1E3L, 0x8DB5A17EL, 0x0FACABD7L,
		0x8E7B8FC9L, 0x57D3EB69L, 0xC774AE72L, 0x431E3BDEL,
		0x80CC7C71L, 0x3CF9BFE6L, 0x5956ED07L, 0xEB1EE324L,
		0xB88B5D93L, 0xFA6301F7L, 0xC4C234CAL, 0x83F6F1EDL,
		0xD9C964D7L, 0x388EB995L, 0x7731A310L, 0x4F505F86L,
		0xCDE3EAD0L, 0xC40AD829L, 0xE49095FDL, 0x2EEECEF7L,
		0x96BDF8E8L, 0x80D82F45L, 0xE0371557L, 0xBD517453L,
		0xFED6C1A2L, 0x98184C10L, 0x547E43DEL, 0x42B3953BL,
		0x2E28D455L, 0x40786303L, 0x59B1165CL, 0x5A4D7F76L,
		0x4DEB2E26L, 0x2D34B285L, 0xD99149B9L, 0xEDCF6434L,
		0x53CB6075L, 0xAF894B39L, 0xB579EF50L, 0xC2A6F57BL,
		0x0FA31EA7L, 0x924B4D54L, 0xBB8BDB7EL, 0x0F9C94FCL,
		0x094D1559L, 0x758FF60EL, 0xE7C1BFB1L, 0x8743680EL,
		0x5424C08BL, 0x0CF9FDA6L, 0xB335CB70L, 0x097224B8L,
		0x3AC3C72AL, 0x05F1CC87L, 0xF3771F9EL, 0x38BE006BL,
		0x2904FDA8L, 0xF0AA8F2AL, 0xCCA2DB7CL, 0x652ADFCCL,
		0xC832F516L, 0x962E44F8L, 0x3CA7461EL, 0x6EF8F7F0L,
		0xD22AFD1AL, 0x87682BA6L, 0x00C9CACAL, 0x97FA3827L,
		0x9C519CBDL, 0xC81A32D0L, 0x072F6D60L, 0x8E426F3AL,
		0x042F7336L, 0x0575600FL, 0x66165956L, 0x354094E6L,
		0xE4AC912BL, 0x1DC1ECCDL, 0x49B774ECL, 0x3D420E4EL,
		0xDF180A53L, 0x88C3265BL, 0x3A567873L, 0x93AA0D4AL,
		0xA7CDDD99L, 0xAFC8BC1AL, 0xFCFECBACL, 0xDCC501B7L,
		0xA395CA86L, 0x4A9D230AL, 0xD2374407L, 0xC46E134BL,
		0x7811CD2AL, 0x68ED97E6L, 0xD7568E6EL, 0x861BF14CL,
		0x62F0D47FL, 0x0F59C3FEL, 0x4B829BF1L, 0x293FC7C7L,
		0x4921A11AL, 0x462560B2L, 0xEC741441L, 0x7127F765L,
		0xC614AC1DL, 0x05AE08A0L, 0x468B7DBAL, 0xF1C55EB3L,
		0xD3FC3EF0L, 0x28B479EFL, 0xC10B0B31L, 0x9EE238C9L,
		}, {
		0xE118F4D7L, 0x2798B3F4L, 0x42545BE2L, 0xD9ED247CL,
		0xB92FB25EL, 0x246EF4A1L, 0xEB99AEBDL, 0x8AC04725L,
		0x5191C6B2L, 0xE0175FAAL, 0xF47A8EA2L, 0x235FD3C8L,
		0xB10684E6L, 0x4E339580L, 0x3CE330F0L, 0xE4C559F2L,
		0x50DF2D94L, 0xD485F9D4L, 0x91F2977DL, 0x3FED1C1AL,
		0xF3DE17BBL, 0xFC13177EL, 0x806469C3L, 0xD76611AFL,
		0x92CD59FFL, 0x6BCD07B0L, 0xE7341629L, 0x66F81989L,
		0xFADB40DEL, 0x8A14211BL, 0x53DC26E5L, 0x535C0192L,
		0x6F833DC1L, 0x8CC167FCL, 0x38794EDDL, 0x9C66E70DL,
		0x084BEDACL, 0x8A187D43L, 0xC207F53CL, 0xA5B27C77L,
		0xE736F47EL, 0x372B507BL, 0x0E76EC6CL, 0xEFDD1DB5L,
		0xCFC2A07BL, 0x86EF4F61L, 0xE478C21EL, 0x4A8FE48AL,
		0x67BAC844L, 0xFB95C664L, 0xD6BE7A3AL, 0xE6BE7DF9L,
		0xFCD715BDL, 0x63BD5E38L, 0x317E391CL, 0x9A7CF7CFL,
		0x96ECAD02L, 0x4C527726L, 0xFF4C9F3BL, 0x23C88A16L,
		0x6467ECBAL, 0xF8DFBA78L, 0xEDEED374L, 0x101B48BEL,
		0x5D480ED4L, 0x72FB9C0DL, 0x81BCCF2DL, 0xAFFB6E96L,
		0x6126926BL, 0x9A17CD19L, 0x529D2F07L, 0x75931666L,
		0xBFC21100L, 0xBB9948E8L, 0xCE746449L, 0x6D4EDBDDL,
		0xBCE69147L, 0x7A875A83L, 0xBE0BE015L, 0x0FC107ABL,
		0xDB6E4751L, 0xC8570AAAL, 0xC141DE73L, 0xA96CEA5BL,
		0x73E5215FL, 0xB4C29902L, 0x95BE87B5L, 0x90D37878L,
		0x176A8535L, 0x8754561AL, 0x856F1FB1L, 0x5D9E4F03L,
		0x4A48A66FL, 0x44722F20L, 0x67EAA8ABL, 0xAC0647B2L,
		0x183B6745L, 0x1A0C3688L, 0xCC4D63A4L, 0xF8BDA982L,
		0x9AE345E6L, 0x3595F937L, 0x41351D9CL, 0x834A3450L,
		0x3411180EL, 0x8350C1C9L, 0xE82EAC98L, 0x4D806942L,
		0x31660846L, 0x789A983EL, 0xE3457F97L, 0xDD147B8DL,
		0x21F12FE4L, 0xE65816C8L, 0xB0EC7AA2L, 0x5B478E71L,
		0x2012A476L, 0xFCA404FFL, 0x321D0295L, 0x80527CC2L,
		0xF853F521L, 0x21ECF46EL, 0xD176290FL, 0xA2391449L,
		0x87AB7335L, 0xB1F944A4L, 0x110018B9L, 0xAA1DE292L,
		0x9C20667DL, 0x5DF58D14L, 0x64D6A6EFL, 0xCFF927DCL,
		0x19725CD8L, 0xCF5EE5B8L, 0x786F3D31L, 0xA54323B9L,
		0xC74E94ADL, 0x0E693282L, 0x45EA82DAL, 0x5C6F4CA3L,
		0xC19D2480L, 0x557D3F26L, 0xA785A9B0L, 0xC46147B6L,
		0xC70EA375L, 0x48025440L, 0xEB56BA11L, 0xDD8319FAL,
		0x9137D1A3L, 0xD3E28380L, 0x3C635CDCL, 0x1A4A97B7L,
		0x7E107EFDL, 0xEEB982C1L, 0xA733CC12L, 0xE537C154L,
		0x329884FBL, 0x4B7E0AB6L, 0x3909434DL, 0x5E53AA3BL,
		0x1C180367L, 0xB9119F01L, 0x28E4543DL, 0x4829E282L,
		0xAECDC2D0L, 0x9C50FAF7L, 0xF8A9F52BL, 0xAB977A08L,
		0x2C4E00C6L, 0x0CE2BC06L, 0x78DC8F5DL, 0x40311443L,
		0x0A161DC7L, 0x735238E3L, 0xCE6B04CBL, 0x16C4E378L,
		0x2ABBBD94L, 0xA9E12DD4L, 0x0B8E93EAL, 0x92FA6A87L,
		0x80ABCB35L, 0x6542D425L, 0x4D08BB54L, 0x2FFBC5C4L,
		0xD353B399L, 0x9CAB6D61L, 0x248E1DD4L, 0x1921D1B1L,
		0x3573198AL, 0x08799608L, 0xF58A0B8FL, 0x7B904FD8L,
		0xCE377322L, 0x31E4002CL, 0xB2D423E7L, 0x1575273AL,
		0xD7A1E640L, 0x558990A9L, 0x8A4D240EL, 0x19AB61A7L,
		0x8A017245L, 0x7255AEFAL, 0x470239CAL, 0x301335CEL,
		0xD7BB1A28L, 0x5480E033L, 0xFD1AD29FL, 0x3A0CB6C8L,
		0xA6CEDD31L, 0x7AC0BE04L, 0x0B83358EL, 0x428BE4C9L,
		0xB8C5730AL, 0x027F05AEL, 0xFDD06859L, 0xBD71FD47L,
		0xACD5F342L, 0x2EC1EED8L, 0xEE4FB44CL, 0x55321F10L,
		0xF8DDD5DAL, 0x65CEE0D3L, 0x03D4CB63L, 0x2C99CD6AL,
		0x97BEA3EAL, 0xAFC5AD1DL, 0x29EE29C6L, 0x4A2E5412L,
		0x48B416D8L, 0x0ADD302BL, 0x0651EB2BL, 0x3EE320FFL,
		0xEBBB6A8AL, 0x66E658FDL, 0x5E884ED4L, 0x04A588B3L,
		0x17806E16L, 0xDABA13BDL, 0xACCE8D50L, 0x5E6A0787L,
		0x192CF341L, 0x459619D0L, 0x5D26A6E9L, 0x24F1EA8EL,
		0xC0033888L, 0x89D57C64L, 0x67BFDD91L, 0x294650CFL,
		0x1E382818L, 0x16E5BF8BL, 0xF81B69BBL, 0xC0AA7502L,
		0x4789CDBDL, 0xBD226C19L, 0xFD7F86C6L, 0xA9E91992L,
		}, {
		0x02FCBE7EL, 0xB1742192L, 0x2C82B659L, 0x7ECE1735L,
		0x03BCA927L, 0xD3A57CA5L, 0x2569AFE4L, 0xF8EBE6BEL,
		0x0CCF4DD2L, 0x92BE8800L, 0x8B26F190L, 0x369C6A52L,
		0xAB0B051DL, 0x73013C18L, 0x025D73D7L, 0x45EFF58DL,
		0x8B9442DAL, 0xFC6BF4F2L, 0x3ED43E84L, 0xCEA0D696L,
		0x0AE92C9EL, 0xAD9D6B55L, 0x59DEAAC5L, 0x0A911794L,
		0x8CDE196BL, 0xBC15F987L, 0xF4BC74CEL, 0xA103A926L,
		0x402D97D9L, 0x5B3FBB24L, 0x562B5E31L, 0x0E761D96L,
		0x0412A8CBL, 0x7C4EED95L, 0x4858BE2AL, 0x462079D2L,
		0xC89205C1L, 0x3A8AF277L, 0xB6CDC841L, 0xFC6B5622L,
		0xD64C47FEL, 0xFFB8B396L, 0x3D69D511L, 0x0A0E2B1FL,
		0x3C021360L, 0x54F538EFL, 0xA3DFE23EL, 0x15622AF9L,
		0x2415F4D1L, 0x054CA35FL, 0x72CAEB9BL, 0x3707293CL,
		0x2DF3D6DEL, 0xA804031AL, 0x47F1079FL, 0x6DE89C53L,
		0xEA9F4F28L, 0x978180DAL, 0x37622050L, 0xB851FF08L,
		0x4047F217L, 0x0F0E2CCEL, 0xB1C3116BL, 0x3F8D15EBL,
		0xA2CC762BL, 0x08C80F91L, 0x736C5EB8L, 0x490CC4EEL,
		0x89AA3F40L, 0x79DFDB55L, 0x2D380657L, 0xB408D03AL,
		0xC9B3A005L, 0x0F820E52L, 0x147EBD51L, 0x9E5C58F6L,
		0x44BE28ECL, 0x41F94A32L, 0x8F4E3FAEL, 0x17C8F050L,
		0x996E469EL, 0x3BF314EAL, 0x94A25ED6L, 0xADA9884DL,
		0xF9B26B73L, 0xA5A8D08DL, 0x067E20EFL, 0xE5D74853L,
		0xD4AAB2D2L, 0x31BC53F8L, 0xE1C22526L, 0x5327C7E4L,
		0x5F978CBDL, 0x8C3FBF16L, 0x29DA5564L, 0xA2F5013FL,
		0xF4EE1993L, 0x9E093D29L, 0xD46BFE45L, 0xB6D13F5AL,
		0xD3A6AFE1L, 0x7EA7F797L, 0x2E040A9AL, 0x8194DADFL,
		0x1D5B80C9L, 0xC7DB9F6AL, 0xE1417AC0L, 0x2D50CC5AL,
		0x57B5EBA3L, 0xCF32EDF0L, 0xF8D83387L, 0x7E8B8824L,
		0xEB1DE85EL, 0x492CC06CL, 0xC725696AL, 0xEC3DC45FL,
		0x5F0F056CL, 0xABD26747L, 0x0D780B40L, 0xCFD2F9C6L,
		0x8093F2EEL, 0x267E4003L, 0xCDE2C3E2L, 0x740DDEFAL,
		0x5097AD8BL, 0x93E36A1DL, 0xC147AF55L, 0x9A9468D5L,
		0xFE6F3162L, 0x30F1FFCEL, 0xA839D23BL, 0xA73D564CL,
		0x2EA7CDEEL, 0xA30911F8L, 0xA0C9BC12L, 0xAA5CCB73L,
		0x22A031C2L, 0xA7ECA526L, 0xAAE5E010L, 0x7D0E0860L,
		0xE91ABFC1L, 0x77A4356FL, 0x52241FF6L, 0x05A7E88DL,
		0x6AB3284FL, 0x7723DDB5L, 0x089D2E69L, 0x379C6849L,
		0x48288FEAL, 0xCD775912L, 0xA78ADE09L, 0xBFB3B0A8L,
		0x4DC0D418L, 0x18E168AAL, 0xAAEA906BL, 0x4C7ED12AL,
		0x25C516D7L, 0xB57EDB32L, 0xC6085EADL, 0x2E167DBCL,
		0xD6022FF7L, 0x03E9789AL, 0x77093101L, 0x96E5C164L,
		0x79FF7C67L, 0x405A19E0L, 0xC9953625L, 0x089D6F11L,
		0xAA33889EL, 0x15226D51L, 0x420F875CL, 0x4D410060L,
		0x2080F0D0L, 0x80F8637DL, 0x2D4A744BL, 0x3C6E111FL,
		0x6BB180AFL, 0xD34D2BC9L, 0x383CC15BL, 0x57DC08ABL,
		0x9FB53B87L, 0x3A77355CL, 0x918015A1L, 0x173419CBL,
		0x1B038AD9L, 0x76D732E1L, 0x72002F88L, 0x46FA30EEL,
		0x2E7DC897L, 0xF7381D98L, 0x986E6C95L, 0xD6F5CF1CL,
		0xAC883E83L, 0xB377E55EL, 0x10E237C0L, 0xA0B97E64L,
		0xBC74D2FFL, 0xDF872755L, 0xDB9B7B2EL, 0x7BC42F65L,
		0x98CCEE93L, 0xD12CEEE0L, 0x6EEFC082L, 0xCAC459E2L,
		0x13743941L, 0x91530E55L, 0xBF08152EL, 0x0602F916L,
		0x112B9722L, 0x800C4260L, 0x9A0FE35FL, 0xB41E5E75L,
		0x178F26FFL, 0x559EFABCL, 0xDBC78FB8L, 0xC3106FB9L,
		0xE14D2198L, 0x087426C6L, 0xC572EF86L, 0xA06A7C34L,
		0x452D2728L, 0x94BC2C33L, 0x02DEEB20L, 0x93DF2841L,
		0xCF977309L, 0xF14D502DL, 0x1D0AB1E0L, 0x0B8C8A41L,
		0xAA4A1ABBL, 0x23ECC44BL, 0x8673D9FAL, 0x77BB09DAL,
		0x3861A5FBL, 0xBE07623BL, 0x1AF70D5EL, 0xCAB2FC68L,
		0xF68259F7L, 0x3B19CE04L, 0x835C17F2L, 0x02057704L,
		0xA28E359DL, 0xA503CBAAL, 0xE8CC5DADL, 0xBDF56D50L,
		0xC21E6D24L, 0x32C1C388L, 0x4567C294L, 0x48A697AEL,
		0x58EB98E7L, 0xC40DB54EL, 0xE63EC482L, 0xBB2A71EEL,
		0xC609DE0EL, 0x478CA573L, 0x01CC8170L, 0xB1BC5ED8L,
		}};

#endif /* _CRYPT_KEY_INPUT_H */
