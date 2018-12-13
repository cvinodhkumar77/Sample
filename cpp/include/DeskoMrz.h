#ifndef DESKO_MRZ_LIB_H
#define DESKO_MRZ_LIB_H

#include <stddef.h>

#ifndef DESKOMRZLIB_USAGE
#ifdef DESKOMRZLIB_EXPORTS
#define DESKOMRZLIB_USAGE extern "C" __declspec(dllexport)
#else
#define DESKOMRZLIB_USAGE extern "C" __declspec(dllimport)
#endif
#endif
#ifndef DESKOMRZLIB_API_CALL
#define DESKOMRZLIB_API_CALL __stdcall
#endif

#ifdef __cplusplus

namespace Desko {
	namespace Mrz {
		extern "C" {


#endif

			/**
			\defgroup Common Common

			Common data types and functions.
			@{
			*/

			/**
			 API major version number.
			*/
			const unsigned int DMRZ_API_VERSION_MAJOR = 1;
			/**
			API minor version number.
			*/
			const unsigned int DMRZ_API_VERSION_MINOR = 2;
			/**
			API revision number.
			*/
			const unsigned int DMRZ_API_VERSION_REVISION = 0;


			/**
			 Operation result code.
			*/
			enum DMRZResult {
				/**
				Operation executed successfully.
				*/
				DMRZ_RESULT_SUCCESS = 0,
				/**
				Generic error on operation.
				*/
				DMRZ_RESULT_FAIL = 1,
				/**
				Operation failed due to access restriction.
				*/
				DMRZ_RESULT_PERMISSION_DENIED = 2,
				/**
				Operation is currently not supported for the given arguments.
				*/
				DMRZ_RESULT_NOT_SUPPORTED = 3,
				/**
				Operation failed due to an invalid argument given by the caller.
				*/
				DMRZ_RESULT_BAD_ARGUMENT = 4,
				/**
				Operation failed due to an invalid object handle.
				*/
				DMRZ_RESULT_INVALID_HANDLE = 5,
			};

			/**
			 Integer representation of #DMRZResult.
			*/
			typedef int DMRZResultIndex;


			
			/**
			Boolean data type.

			\see #DMRZ_FALSE, #DMRZ_TRUE.
			*/
			typedef int DMRZBool;

			/**
			Boolean true.
			*/
			const DMRZBool DMRZ_FALSE = 0;

			/**
			Boolean false.
			*/
			const DMRZBool DMRZ_TRUE = 1;

			

			/**
			Abstract object handle.
			
			\see #DMRZDestroyHandle
			*/
			typedef void * DMRZObjectHandle;

			/**
			Destroy object and free all depending resources.

			\param[in] handle  Object handle.

			\see #DMRZCreateMrzDescriptor, #DMRZCreateSubstitutionRules
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZDestroyHandle(DMRZObjectHandle handle);


			/** @}	*/


			/**
			\defgroup MrzDescriptor MRZ Descriptor

			Functionality for MRZ analysis and validation provided by MRZ Descriptor objects.
			@{
			*/
			/**
			MrzDescriptor object handle.
			\see #DMRZCreateMrzDescriptor().
			*/
			typedef void * DMRZMrzDescriptorHandle;

			

			/**
			Create new MRZ descriptor object.

			This function allocates resources which are freed only by an explicit call to DMRZDestroyHandle().

			\returns handle for newly created descriptor object.

			\see DMRZDestroyHandle(), DMRZMrzDescriptorHandle.
			*/
			DESKOMRZLIB_USAGE DMRZMrzDescriptorHandle DESKOMRZLIB_API_CALL DMRZCreateMrzDescriptor();


			/**
			Reset the MRZ descriptor.

			\param[in,out] descriptor  Descriptor object to be reset.

			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZResetMrzDescriptor(DMRZMrzDescriptorHandle descriptor);

			/**
			Parse MRZ string and fill descriptor object.

			Note that any 8-bit encoded ASCII string must be converted to a  wchar_t string before being passed to this function.

			\warning This function will return #DMRZ_RESULT_PERMISSION_DENIED if there is no supported DESKO device connected to the system.

			\param[in,out] descriptor  Descriptor object to store mrz information.
			\param[in]  mrz  Input MRZ string. UTF-16 encoded, null-terminated C string.
			\return DMRZ_RESULT_SUCCESS on success or respective error code.

			\see DMRZCreateMrzDescriptor().

			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZParseMrz(DMRZMrzDescriptorHandle descriptor, const wchar_t * mrz);

			/**
			\defgroup DocTypes Document Types

			Document type identification.
			@{
			*/

			/**
			 Document type.

			 \see #DMRZGetDocType().
			 */
			enum DMRZDocType {
				/**
				Document type unknown.

				- Specification: undefined.
				- Layout: any.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_UNKNOWN = 0,

				/**
				Unknown 1-line document.
				
				- Specification: undefined.
				- Layout: 1 line.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_UNKNOWN_1LINE = 1,

				/**
				Unknown 2-line document.

				- Specification: undefined.
				- Layout: 2 lines.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_UNKNOWN_2LINE = 2,

				/**
				Unknown 3-line document.

				- Specification: undefined.
				- Layout: 3 lines.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_UNKNOWN_3LINE = 3,

				/**
				ICAO 9303 document of format TD1 (credit card size).

				- Specification: ICAO 9303.
				- Layout: 3 lines / 30 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_ICAO_TD1 = 100,

				/**
				ICAO 9303 document of format TD2.

				- Specification: ICAO 9303.
				- Layout: 2 lines / 36 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_ICAO_TD2 = 101,

				/**
				ICAO 9303 Machine Readable Passports (MRPs) and other TD3 size machine readable documents.

				- Specification: ICAO 9303.
				- Layout: 2 lines / 44 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_ICAO_PASSPORT = 102,

				/**
				ICAO 9303 Machine Readable Visa (MRV) Size B.

				- Specification: ICAO 9303.
				- Layout: 2 lines / 36 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_ICAO_MRVB = 103,

				/**
				ICAO 9303 Machine Readable Visa (MRV) Size A.

				- Specification: ICAO 9303.
				- Layout: 2 lines / 44 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_ICAO_MRVA = 104,

				/**
				Documents similar to TD2 or TD3

				- Specification: undefined.
				- Layout: 2 lines / 35, 36 or more characters. All lines of same length.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_ICAO_FREE = 105,

				/**
				China: Resident Identity Card.

				- Specification: unknown.
				- Layout: 1 line / 18 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_CHN_RESIDENT_ID = 200,
				
				/**
				China: Exit-Entry Permit for Traveling to and from Hong Kong and Macao (中华人民共和国往来港澳通行证).

				- Specification: unknown.
				- Layout: 1 line / 30 characters
				- Check sum validation: supported.
				*/
				DMRZ_DOC_CHN_EEP_HK_MAC = 201,

				/**
				China: Exit-Entry Permit for Traveling to and from Hong Kong and Macao (中华人民共和国往来港澳通行证).

				\deprecated Use #DMRZ_DOC_CHN_EEP_HK_MAC instead.
				*/
				DMRZ_DOC_CHN_EEP = 201,

				/**
				China: Exit-Entry Permit for Traveling to and from Taiwan (卡式往來台灣通行證).

				- Specification: unknown.
				- Layout: 1 line / 30 characters
				- Check sum validation: supported.
				*/
				DMRZ_DOC_CHN_EEP_TAIWAN = 202,

				/**
				China: Mainland Travel Permit for Hong Kong and Macao Residents (港澳居民来往内地通行证) (1999-2013).

				- Specification: unknown.
				- Layout: 3 lines / 30 characters.
				- Check sum validation: not implemented.
				*/
				DMRZ_DOC_CHN_MAINLAND_TRAVEL_PERMIT_HK_MAC_1999 = 203,

				/**
				China: Mainland Travel Permit for Hong Kong and Macao Residents (港澳居民来往内地通行证) (since 2013).

				- Specification: unknown.
				- Layout: 3 lines / 30 characters.
				- Check sum validation: not implemented.
				*/
				DMRZ_DOC_CHN_MAINLAND_TRAVEL_PERMIT_HK_MAC_2013 = 204,

				/**
				China: Mainland Travel Permit for Taiwan Residents (台湾居民来往大陆通行证).

				- Specification: unknown.
				- Layout: 3 lines / 30 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_CHN_MAINLAND_TRAVEL_PERMIT_TAIWAN = 205,


				/**
				France: Identity Card (Carte nationale d'identité)

				- Specification: unknown.
				- Layout: 2 lines / 36 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_FRA_ID = 300,

				/**
				For future use.
				*/
				DMRZ_DOC_FRA_CAR_REGISTRATION = 301,

				/**
				Switzerland: Driving license (Führerausweis)

				- Specification: unknown.
				- Layout: 1 lines / 9 characters + 2 lines / 30 characters.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_CHE_DRIVING_LICENSE = 310,

				/**
				Liechtenstein: Driving license (Führerausweis)

				- Specification: unknown.
				- Layout: 2 lines  or 3 lines / 30 characters.
				- Check sum validation: not supported.
				*/
				DMRZ_DOC_LIE_DRIVING_LICENSE = 311,
				/**
				ISO driving license.

				- Specification: unknown.
				- Layout: 1 line / 30 characters.
				- Check sum validation: supported.
				*/
				DMRZ_DOC_ISO_DRIVING_LICENSE = 312,

			};

			/**
			Integer Representation of DMRZDocType.

			\see #DMRZDocType.
			*/
			typedef int DMRZDocTypeIndex;


			/**
			Get derived document type of parsed MRZ.

			\param[in] descriptor   The MRZ descriptor object.
			\param[out] docType    Document type index corresponding to values of enumeration #DMRZDocType
			\return #DMRZ_RESULT_SUCCESS on success or respective error code.
			
			\see #DMRZParseMrz(), #DMRZDocType.
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZGetDocType(DMRZMrzDescriptorHandle descriptor, DMRZDocTypeIndex * docType);
			/**
			 @}
			*/
		

			/**
			 \defgroup GetFields MRZ Fields

			 Request data fields of the MRZ parsed by an MRZ descriptor.
			 @{
			*/

			/**
			Document field identifier.
			
			A document field is a substring of the MRZ which conveys a specific meaning.
			The position of this field depends on the specific MRZ layout given by the document type.
			So in order to get the actual field data, the MRZ must be parsed by MrzDescriptor.parseMrz(String)
			and respective DocField value must be passed
			to DMRZGetField().
			
			*/
			enum DMRZDocField {
				/**
				Complete parsing input.
				*/
				DMRZ_FIELD_COMPLETE = 0,
				
				/**
				Characters of the first MRZ line, not including the line separator.
				*/
				DMRZ_FIELD_LINE_FIRST = 1,
				
				/**
				Characters of the second MRZ line, not including the line separator.
				*/
				DMRZ_FIELD_LINE_SECOND = 2,
				
				/**
				Characters of the third MRZ line, not including the line separator.
				*/
				DMRZ_FIELD_LINE_THIRD = 3,

				/**
				Document code.

				Usually the first two characters of the MRZ identifying the document type.
				*/
				DMRZ_FIELD_DOC_CODE = 4,

				/**
				Issuing State or organization.

				For any ICAO 3903 document:
				The three-letter code specified in
				Doc 9303-3. Spaces are represented by filler
				characters (<).
				*/
				DMRZ_FIELD_DOC_ISSUER = 5,

				/**
				Primary document number.

				The number or primary part of the document number.

				Note: This field does not provide a unique identifier for some document types. For details see comments of field #DMRZ_FIELD_DOC_NUMBER_COMPOSITE.

				
				*/
				DMRZ_FIELD_DOC_NUMBER = 6,

				/**
				Checksum of the principle document number.

				This checksum refers to field #DMRZ_FIELD_DOC_NUMBER.
				*/
				DMRZ_FIELD_DOC_NUMBER_CHECKSUM = 7,

				/**
				Optional extension of the document number.

				Note that some documents need this number in combination with the primary document number in order to identify the document.
				For details see comments for field #DMRZ_FIELD_DOC_NUMBER_COMPOSITE.

				*/
				DMRZ_FIELD_DOC_NUMBER_OPTIONAL = 8,

				/**
				Composite document number.

				This field provides a unique document identifier.
				For most document types the contents of this field is equivalent to the principal document number of field #DMRZ_FIELD_DOC_NUMBER .
				On some documents the principal document number does not sufficiently identify the document
				but requires the additional data of field #DMRZ_FIELD_DOC_NUMBER_OPTIONAL for disambiguation.

				The following documents are known to have this issue:
				- For #DMRZ_DOC_ICAO_TD1 and #DMRZ_DOC_ICAO_TD2 field #DMRZ_FIELD_DOC_NUMBER has up to 9 characters. All exceeding characters are part of #DMRZ_FIELD_DOC_NUMBER_OPTIONAL.
				- For #DMRZ_DOC_CHN_MAINLAND_TRAVEL_PERMIT_HK_MAC_2013 field #DMRZ_FIELD_DOC_NUMBER contains the 9 digits identifying the permit. Field #DMRZ_FIELD_DOC_NUMBER_OPTIONAL
				  contains a sequence number. On renewal of the document, the sequence number is increased but the permit number remains the same.

				*/
				DMRZ_FIELD_DOC_NUMBER_COMPOSITE = 9,
				
				/**
				Checksum of composite document number.

				If available, an overall checksum for the composite document number.
				*/
				DMRZ_FIELD_DOC_NUMBER_COMPOSITE_CHECKSUM = 10,

				/**
				Birth date of the document holder.

				Format: YYMMDD; note that filler characters are used in some documents to indicate unknown digits.
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE = 11,

				/**
				Year of birth date of the document holder.

				Format: YY; note that filler characters are used in some documents to indicate unknown digits.
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE_YEAR = 12,

				/**
				Month of birth date of the document holder.

				Format: MM; note that filler characters are used in some documents to indicate unknown digits.
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE_MONTH = 13,

				/**
				Day of birth date of the document holder.

				Format: DD; note that filler characters are used in some documents to indicate unknown digits.
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE_DAY = 14,

				/**
				Checksum of the holder's birth date
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE_CHECKSUM = 15,

				/**
				Sex of the holder.

				For ICAO 9303 compliant documents:
				'M' for male, 'F' for female, '<' if undefined.
				*/
				DMRZ_FIELD_HOLDER_SEX = 16,


				/**
				Expiry date of the document.

				Format: YYMMDD
				*/
				DMRZ_FIELD_DOC_EXPIRY_DATE = 17,

				/**
				Expiry year of the document.

				Format: YY
				*/
				DMRZ_FIELD_DOC_EXPIRY_DATE_YEAR = 18,

				/**
				Expiry month of the document.

				Format: YY
				*/
				DMRZ_FIELD_DOC_EXPIRY_DATE_MONTH = 19,

				/**
				Expiry day of the document.

				Format: DD
				*/
				DMRZ_FIELD_DOC_EXPIRY_DATE_DAY = 20,

				/**
				Checksum of the document expiry date.
				*/
				DMRZ_FIELD_DOC_EXPIRY_DATE_CHECKSUM = 21, 

				/**
				Nationality of holder

				For any ICAO 3903 document:
				The three-letter code specified in
				Doc 9303-3 shall be used. Spaces
				are replaced by filler
				characters (<).

				*/
				DMRZ_FIELD_HOLDER_NATIONALITY = 22,

				/**
				Optional field content.
				*/
				DMRZ_FIELD_OPTIONAL = 23,

				/**
				Checksum for optional field.
				*/
				DMRZ_FIELD_OPTIONAL_CHECKSUM = 24,

				/**
				Composite data for check sum calculation.

				Synthetic field containing the input of the composite checksum calculation.
				*/
				DMRZ_FIELD_COMPOSITE = 25,

				/**
				Composite check sum.
				*/
				DMRZ_FIELD_COMPOSITE_CHECKSUM = 26,

				/**
				Name of holder. Complete field including all separating and trailing fillers.
				*/
				DMRZ_FIELD_HOLDER_NAME = 27,

				/**
				Primary name(s) of holder. Name parts are separated by fillers. No trailing fillers.
				*/
				DMRZ_FIELD_HOLDER_NAME_PRIMARY = 28, 

				/**
				Secondary name(s) of holder. Name parts are separated by fillers. No trailing fillers.
				*/
				DMRZ_FIELD_HOLDER_NAME_SECONDARY = 29,

				/**
				Tertiary name(s) of holder. Name parts are separated by fillers. No trailing fillers.

				Tertiary names are currently only supported by the French ID card.
				On ICAO 9303 travel documents tertiary names are not specified. So all given names, including the middle name, are considered secondary names.
				*/
				DMRZ_FIELD_HOLDER_NAME_TERTIARY = 30,

				/**
				Address or address code of holder.
				*/
				DMRZ_FIELD_HOLDER_ADDRESS = 31,

				/**
				Additional number to disambiguate holders with the same personal data.
				*/
				DMRZ_FIELD_HOLDER_DISAMBIGUATION = 32,

				/**
				Year of birth of the document holder.

				This field provides the full 4-digit year if it is printed on the document.

				See also the notes on #DMRZ_FLAGS_YY_TO_YYYY about consistent handling of year information.

				Format: YYYY
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE_YEAR_FULL = 33,
				
				/**
				Birth date of the document holder with 4-digit year.

				This field provides the full 4-digit year if it is printed on the document.

				See also the notes on #DMRZ_FLAGS_YY_TO_YYYY about consistent handling of year information.

				Format: YYYYMMDD.
				*/
				DMRZ_FIELD_HOLDER_BIRTH_DATE_FULL = 34,

				/**
				Configuration field of ISO driving license.

				For documents of type #DMRZ_DOC_ISO_DRIVING_LICENSE this is a single character at position 2 (array index 1) of the MRZ.
				*/
				DMRZ_FIELD_IDL_CONFIGURATION = 35,

				/**
				Discretionary field of ISO driving license.

				For documents of type #DMRZ_DOC_ISO_DRIVING_LICENSE this is the data at positions 3 to 29 (array index 2 to 28) of the MRZ.
				The format of this data is defined at the discretion of the issuing authority.
				*/
				DMRZ_FIELD_IDL_DISCRETIONARY = 36,


				/**
				Checksum of document number extension.

				For details see comments for field #DMRZ_FIELD_DOC_NUMBER_COMPOSITE.
				*/
				DMRZ_FIELD_DOC_NUMBER_OPTIONAL_CHECKSUM = 37,

				/**
				Number identifying the holder of the document.
				*/
				DMRZ_FIELD_HOLDER_NUMBER = 38,

				/**
				Checksum of field #DMRZ_FIELD_HOLDER_NUMBER .
				*/
				DMRZ_FIELD_HOLDER_NUMBER_CHECKSUM = 39,

				/**
				Administrative authority.
				*/
				DMRZ_FIELD_DOC_AUTHORITY = 40,
			};

			/**
			Integer representation of #DMRZDocField.

			\see #DMRZDocField.
			*/
			typedef int DMRZDocFieldIndex;

			/**
			Flags for function #DMRZGetField().

			\see #DMRZ_FLAGS_NONE, #DMRZ_FLAGS_SPACE_FILLER, #DMRZ_FLAGS_TRIM, #DMRZ_FLAGS_LOWER, #DMRZ_FLAGS_FIRST_UPPER, #DMRZ_FLAGS_YY_TO_YYYY
			*/
			typedef unsigned int DMRZGetFlags;

			/**
			Get field flag: No flags.
			*/
			const DMRZGetFlags DMRZ_FLAGS_NONE = 0x00000000;

			/**
			Get field flag: replace filler '<' by space ' '.
			*/
			const DMRZGetFlags DMRZ_FLAGS_SPACE_FILLER = 0x00000001;

			/**
			Get field flag: drop trailing fillers
			*/
			const DMRZGetFlags DMRZ_FLAGS_TRIM = 0x00000004;

			/**
			Get field flag: convert all characters to lower case.
			*/
			const DMRZGetFlags DMRZ_FLAGS_LOWER = 0x00000008;

			/**
			Get field flag: on lower case conversion, keep upper case for the first character of each word.

			Needs to be combined with DMRZ_FLAGS_LOWER to have any effect.
			*/
			const DMRZGetFlags DMRZ_FLAGS_FIRST_UPPER = 0x00000010;

			/**
			Guess century of year and convert from 2 digits to 4 digits.

			This function either derives the century information from other MRZ contents or it guesses depending on the field type.

			The function is applicable only for the following fields:

			- #DMRZ_FIELD_DOC_EXPIRY_DATE_YEAR: For a given year YY, the century CC will be 19, 20 or 21 depending which of CCYY is closer to the current year.
			- #DMRZ_FIELD_HOLDER_BIRTH_DATE_YEAR: For a given year YY, the century will be the last one or the current one depending on which of CCYY is not in the future.
			Note that this strategy will return a false date for holders of age 100 or older.
			*/
			const DMRZGetFlags DMRZ_FLAGS_YY_TO_YYYY = 0x00000020;

			/**
			 Get parsed field text.

			 \param[in] descriptor   The MRZ descriptor object.
			 \param[in] field        Field index corresponding to values of enumeration #DMRZDocField
			 \param[out] text        Target buffer for field text. Null-terminated UTF-16 wide character string.
			 \param[in] text_size    Size of target buffer in (i.e., number of wchar_t elemnts). Field text longer than text_size-1 gets truncated.
			 \param[in] flags        Text conversion flags. May be 0.
			 \return #DMRZ_RESULT_SUCCESS on success or respective error code.

			 \see #DMRZParseMrz(), #DMRZDocField, #DMRZGetFlags.
			 */
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZGetField(DMRZMrzDescriptorHandle descriptor, DMRZDocFieldIndex field, wchar_t * text, int text_size, DMRZGetFlags flags);


			/**
			@}
			*/

	

			/**
			\defgroup Validation Validation
			Validate the MRZ parsed by an MRZ descriptor.
			@{
			*/

			/**
			Validate strict format.

			The format of the MRZ is considered strict if, for the detected document type, each character is within the allowed range.

			\param[in] descriptor   The MRZ descriptor object.
			\param[out] valid       DMRZ_TRUE if all characters are correct.

			\return #DMRZ_RESULT_SUCCESS on success or respective error code.

			\see #DMRZGetDocType
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZValidateCharacters(DMRZMrzDescriptorHandle descriptor, DMRZBool * valid);


			/**
			Validate ICAO compliance.

			The operation succeeds if the format of the MRZ corresponds to a valid ICAO compliant format.
			There is no checksum validation.

			The function returns `*valid==true` if the following conditions hold:

			The document type is one of 

			- #DMRZ_DOC_ICAO_TD1
			- #DMRZ_DOC_ICAO_TD2
			- #DMRZ_DOC_ICAO_PASSPORT
			- #DMRZ_DOC_ICAO_MRVB
			- #DMRZ_DOC_ICAO_MRVA
			
			and the MRZ format is strict in the sense of function #DMRZValidateCharacters().

			\param[in] descriptor   The MRZ descriptor object.
			\param[out] valid       DMRZ_TRUE if the MRZ is ICAO compliant.

			\return #DMRZ_RESULT_SUCCESS on success or respective error code.

			\see #DMRZGetDocType, #DMRZValidateCharacters
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZValidateIcao(DMRZMrzDescriptorHandle descriptor, DMRZBool * valid);


			/**
			 Validate all checksums.

			 Note that this function will always return valid==false unless
			 - The document type is supported and has valid check sums (see #DMRZDocType), and
			 - The the descriptor succeeds when passed to #DMRZValidateCharacters().

			 \param[in] descriptor   The MRZ descriptor object.
			 \param[out] valid       DMRZ_TRUE if all checksums are correct.
			 
			 \return #DMRZ_RESULT_SUCCESS on success or respective error code. #DMRZ_RESULT_NOT_SUPPORTED if checksum validation is not supported for the respective document type.
			 */
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZValidateAllChecksums(DMRZMrzDescriptorHandle descriptor, DMRZBool * valid);

			/**
			Check that the document is not expired.

			For reliable document types, there will be a preceding check sum test. In case of an invalid check sum,
			the actual expiry check will be skipped and the returned result will be #DMRZ_FALSE.

			The precision of the result highly depends on the system clock. The reference time is the system time of the local time zone, not UTC.

			\param[in] descriptor   The MRZ descriptor object.
			\param[in] minDaysLeft  Minimum number of valid days left.
			\param[out] valid       DMRZ_TRUE if the document expiry date is at least minDaysLeft days in the future. #DMRZ_FALSE otherwise.
			
			\return #DMRZ_RESULT_SUCCESS on success or respective error code. #DMRZ_RESULT_NOT_SUPPORTED if expiry date validation is not supported for the respective document type.
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZValidateExpiryDate(DMRZMrzDescriptorHandle descriptor, int minDaysLeft, DMRZBool * valid);

			/**
			Check that the holder of the document is of a certain age or older.

			For reliable document types, there will be a preceding check sum test. In case of an invalid check sum,
			the actual age check will be skipped and the returned result will be #DMRZ_FALSE.

			The test takes incomplete dates into account: in any situations of uncertainty, the result will be #DMRZ_FALSE.

			The precision of the result highly depends on the system clock. The reference time is the system time of the local time zone, not UTC.

			Example:

			- Current date: 2019-03-14, Holder birth date: 010305 (i.e., 2001-03-05), Check for age 18 -> #DMRZ_TRUE
			- Current date: 2019-03-14, Holder birth date: 0103<< (i.e., 2001-03-??), Check for age 18 -> #DMRZ_FALSE

			\param[in] descriptor   The MRZ descriptor object.
			\param[in] age          Minimum age of holder to pass the test.
			\param[out] valid       #DMRZ_TRUE if the document expiry date is in the future.
			\return #DMRZ_RESULT_SUCCESS on success or respective error code. #DMRZ_RESULT_NOT_SUPPORTED if minimum age validation is not supported for the respective document type.
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZValidateMinimumAge(DMRZMrzDescriptorHandle descriptor, int age, DMRZBool * valid);


			/**
			 Check sum algorithm.
			 */
			enum DMRZCheckSumAlgorithm {

				/**
				Checksum algorithm undefined or not supported.
				*/
				DMRZ_CHECKSUM_UNDEFINED = -1,

				/**
				Checksum algorithm according to ICAO 9303.

				This algorithm is used for official ICAO travel documents.
				*/
				DMRZ_CHECKSUM_ICAO9303 = 0,

				/**
				Checksum algorithm used on China resident ID according to ISO 7064.

				*/
				DMRZ_CHECKSUM_ISO7064_CHINA = 1,

			};

			/**
			Integer Representation of DMRZDocType.

			\see #DMRZDocType.
			*/
			typedef int DMRZCheckSumAlgorithmIndex;


			/**
			 Get the checksum algorithm used by the current document.

			 \param[in] descriptor  The MRZ descriptor object.
			 \param[out] algorithm  The checksum algorithm used by the MRZ.
			 \return #DMRZ_RESULT_SUCCESS on success or respective error code.
			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZGetChecksumAlgorithm(DMRZMrzDescriptorHandle descriptor, DMRZCheckSumAlgorithmIndex * algorithm);

			/**
			 Calculate checksum.

			 \param[in] text        MRZ field data, i.e., a null-terminated substring of the MRZ.
			 \param[in] algorithm   Algorithm to use for check sum calculation.
			 \param[out] checksum   Calculated Checksum.

			 \return #DMRZ_RESULT_SUCCESS on success or respective error code.
			 */
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZCalculateChecksum(const wchar_t * text, DMRZCheckSumAlgorithmIndex algorithm, int * checksum);

			/**
			@}
			*/

			/**
			@}
			*/

			/**
			\defgroup Substitution Substitution Rules

			Substitution rules objects are used to perform automatic substitution of MRZ field text.
			These objects are created with function #DMRZCreateSubstitutionRules(), which returns a #DMRZSubstitutionRulesHandle as object reference.
			In order to release the associated resources, #DMRZDestroyHandle() should be called on the handle if the object is no longer needed.

			A substitution rules object represents a list of rules, each consisting of a match pattern and the text to be used as replacement.
			When #DMRZSubstitute() is applied to an MRZ field text, the first rule will be used which has a matching pattern and the respective replacement text will be returned.
			The search for a suitable match is performed in the order defined by the list of rules. If no pattern matches, the original input string  will be returned.

			There are basically two ways of configuring the substitution rules:

			- By filling the initially empty list with a set of rules with repeated calls to #DMRZAppendRule(). The order of calls determines the order of the rules set. A final call to #DMRZAppendDefaultRule() 
			will provide a default string if none of the previous rules matches.
			\code
			DMRZAppendRule(rules, L"D<<", L"Federal Republic of Germany");
			DMRZAppendRule(rules, L"AUT", L"Republic of Austria");
			DMRZAppendDefaultRule(rules, L"unknown");
			\endcode
			- By a CSV text file read either from a UTF-8 encoded file (#DMRZInitRulesFromFile()) or from a UTF-16 encoded in-memory text buffer (#DMRZInitRulesFromMemory()).
			  Note that the pattern of the default must be given as *regular expression* `.*`.
			  Each line must be terminated by either *carriage return* (`\n`, UNIX style) or *carriage return + line feed* (`\r\n`, Windows style). The field separator is a semicolon (`;`) rather than a comma.
			\verbatim
			D<<;Federal Republic of Germany
			AUT;Republic of Austria
			.*;unknown
			\endverbatim

			Note that search patterns are actually regular expressions according to (ECMA syntax).

			The following code shows a full session in context:

			\code

			// result codes should always be DMRZ_RESULT_SUCCESS. Checks are important but are omitted here for readability.
			DMRZResult result = DMRZ_RESULT_SUCCESS; 
			wchar_t mrz[] =
				L"C1AUT0223435320EAC9730050292<<\r"
				L"6507143F1812121CAN<<<<<<<<<<<5\r"
				L"MILLER<<JOHN<RICARDO<<<<<<<<<<";

			DMRZMrzDescriptorHandle descriptor;
			DMRZSubstitutionRulesHandle rules;

			wchar_t countryCode[512];
			wchar_t countryFullName[512];

			descriptor = DMRZCreateMrzDescriptor();

			result = DMRZParseMrz(descriptor, mrz);
			result = DMRZGetField(DMRZ_FIELD_DOC_ISSUER, countryCode, 512);
			
			// countryCode == "AUT"

			rules = DMRZCreateSubstitutionRules();
			result = DMRZInitRulesFromFile(rules, L"icao9303countries.csv");
			result = DMRZSubstitute(rules, countryCode, countryFullName, 512);

			// countriesFullName == "Republic of Austria"

			result = DMRZDestroyHandle(rules);
			result = DMRZDestroyHandle(descriptor);
			\endcode


			@{
			*/

			/**
			Abstract object handle.

			\see #DMRZCreateSubstitutionRules().
			*/
			typedef void * DMRZSubstitutionRulesHandle;

			/**
			Create new substitution rules object.

			\returns handle for newly created substitution rules object.
			\see #DMRZSubstitutionRulesHandle.
			*/
			DESKOMRZLIB_USAGE DMRZMrzDescriptorHandle DESKOMRZLIB_API_CALL DMRZCreateSubstitutionRules();

			/**
			 Clear all entries from the substitution rules.

			 \param[in] rules  handle of substitution rules object.
			 \return #DMRZ_RESULT_SUCCESS on success or respective error code.

			 */
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZClearRules(DMRZSubstitutionRulesHandle rules);

			/**

			Read substitution rules from file.

			A substitution rules file is a UTF-8 encoded comma-separated values (CSV) file.

			Each line of the CSV file is terminated by "\r\n" (Windows style) or "\n" (UNIX style). The final line ending of the file may be omitted.

			A line consists of of a single substitution rule defined by the first two fields. These fields are are separated by a semicolon.

			\verbatim
			D<<;Federal Republic of Germany
			AUT;Republic of Austria
			.*;unknown
			\endverbatim

			The first field of each line contains a match pattern (regular expression, ECMA syntax).
			The second field contains the substitute text.
			There should not be more then two fields. The third and all following fields are reserved for future use.

			The order of execution is from top to bottom.
			For a given input string, the substitution text of the first matching pattern will be returned
			by function #DMRZSubstitute(). If no pattern matches, the original string will be returned unchanged.
			If a default substitution is required, the pattern of the last entry should be ".*", which matches for any given input string.

			\param[in] rules  handle of substitution rules object.
			\param[in] filename File path of the CSV file as null-terminated UTF-16 string.

			\return #DMRZ_RESULT_SUCCESS on success or respective error code.

			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZInitRulesFromFile(DMRZSubstitutionRulesHandle rules, const wchar_t * filename);

			/**

			Read substitution rules from memory.

			This function has the same behaviour as #DMRZInitRulesFromFile() except the data is read from a wide-character string (UTF-16).

			\param[in] rules  handle of substitution rules object.
			\param[in] csvData Mapping definition (see #DMRZInitRulesFromFile() ). null-terminated wide-character string.

			\return #DMRZ_RESULT_SUCCESS on success or respective error code.

			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZInitRulesFromMemory(DMRZSubstitutionRulesHandle rules, const wchar_t * csvData);

			/**
			 Append a substitution rule.

			 The substitution rule will be added as last entry. That means that it has the lowest priority of all substitution rules.
			 If a different order of priorities is required, then the substitution rules must be cleared with #DMRZClearRules()
			 and all rules must be reinserted in the intended order of priority.

			 \param[in] rules        Handle of substitution rules object.
			 \param[in] pattern    Regular expression to be used as match pattern. (null-terminated UTF-16 string)
			 \param[in] substitute Text to be returned by DMRZ_SubstitutionMapSubstitute() if the input string matches. (null-terminated UTF-16 string)

			 \return #DMRZ_RESULT_SUCCESS on success or respective error code.

			 */
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZAppendRule(DMRZSubstitutionRulesHandle rules, const wchar_t * pattern, const wchar_t * substitute);

			/**
			 Append default rule.

			 This function is equivalent to calling #DMRZAppendRule() with pattern ".*".

			 Note that this function adds a rule for matching any string. I.e., it is the last meaningful rule and any rule appended later will be ignored.

			 \param[in] rules        Handle of substitution rules object.
			 \param[in] substitute Text to be returned by #DMRZSubstitute() if the input string matches. (null-terminated UTF-16 string)

			 \return #DMRZ_RESULT_SUCCESS on success or respective error code.

			 */
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZAppendDefaultRule(DMRZSubstitutionRulesHandle rules, const wchar_t * substitute);

			/**
			Apply the substitution rules to an input text.

			The order of execution is defined by the order of lines in the file loaded by #DMRZInitRulesFromFile()
			or the order of calls to #DMRZAppendRule() respectively.

			For a given input string, the substitution text of the first matching rule will be returned.
			If there is no rule with a matching pattern, the original string will be returned unchanged.
			If a default substitution is required, the pattern of the last entry should be ".*", which matches for any given input string.

			Example:

			\code
			wchar_t outText[512];
			DMRZSubstitutionRulesHandle rules;

			// Create and prepare rule set...
			rules = DMRZCreateSubstitutionRules();
			DMRZAppendRule(rules, L"M",L"male");
			DMRZAppendRule(rules, L"F",L"female");

			// Use rule set...

			DMRZSubstitute(rules, L"<", outText, 512);

			// No rule matches: outText == L"<"

			// Append default rule
			DMRZAppendDefaultRule(rules, L"unknown");

			DMRZSubstitute(rules, L"<", outText, 512);

			// Default rule matches: outText == L"unknown"

			DMRZDestroyHandle(rules);

			\endcode



			\param[in] rules          Handle of substitution rules object.
			\param[in] inText        Input text. (null-terminated UTF-16 string)
			\param[out] outText      Substituted output text. (null-terminated UTF-16 string)
			\param[in] outTextSize  Maximum size of target buffer outText. If the size is too small, the text will be truncated.

			\return DMRZ_RESULT_SUCCESS on success or respective error code.

			*/
			DESKOMRZLIB_USAGE DMRZResultIndex DESKOMRZLIB_API_CALL DMRZSubstitute(DMRZSubstitutionRulesHandle rules, const wchar_t * inText, wchar_t * outText, int outTextSize);

			/** @}	*/

#ifdef __cplusplus
		}
	}
}

#endif



#endif
