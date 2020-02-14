#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
@class WebMainService_HelloWorld;
@class WebMainService_HelloWorldResponse;
@class WebMainService_GetMenusByUserRoleCN;
@class WebMainService_GetMenusByUserRoleCNResponse;
@class WebMainService_GetDefaultConfigByUserJID;
@class WebMainService_GetDefaultConfigByUserJIDResponse;
@class WebMainService_GetRolesByUserJIDString;
@class WebMainService_GetRolesByUserJIDStringResponse;
@class WebMainService_PadUser;
@class WebMainService_PadUserResponse;
@class WebMainService_GetHospitalByUser;
@class WebMainService_GetHospitalByUserResponse;
@class WebMainService_GetDepartmentsByHealthOrgID;
@class WebMainService_GetDepartmentsByHealthOrgIDResponse;
@class WebMainService_GetHospital;
@class WebMainService_GetHospitalResponse;
@class WebMainService_GetClerks;
@class WebMainService_GetClerksResponse;
@class WebMainService_GetClertEx;
@class WebMainService_GetClertExResponse;
@class WebMainService_GetDataCenter;
@class WebMainService_GetDataCenterResponse;
@class WebMainService_AuthorizeUserMenu;
@class WebMainService_ArrayOfString;
@class WebMainService_AuthorizeUserMenuResponse;
@class WebMainService_GetAllHospitals;
@class WebMainService_GetAllHospitalsResponse;
@class WebMainService_DeleteClerk;
@class WebMainService_DeleteClerkResponse;
@class WebMainService_Get21CNClerk;
@class WebMainService_Get21CNClerkResponse;
@class WebMainService_CreateRandomAuthorizeCode;
@class WebMainService_CreateRandomAuthorizeCodeResponse;
@class WebMainService_GetRandomAuthorizeCode;
@class WebMainService_GetRandomAuthorizeCodeResponse;
@interface WebMainService_HelloWorld : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_HelloWorld *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_HelloWorldResponse : NSObject {
	
/* elements */
	NSString * HelloWorldResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_HelloWorldResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * HelloWorldResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetMenusByUserRoleCN : NSObject {
	
/* elements */
	NSString * sUserJID;
	NSString * sWebSiteIP;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetMenusByUserRoleCN *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
@property (retain) NSString * sWebSiteIP;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetMenusByUserRoleCNResponse : NSObject {
	
/* elements */
	NSString * GetMenusByUserRoleCNResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetMenusByUserRoleCNResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetMenusByUserRoleCNResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetDefaultConfigByUserJID : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetDefaultConfigByUserJID *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetDefaultConfigByUserJIDResponse : NSObject {
	
/* elements */
	NSString * GetDefaultConfigByUserJIDResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetDefaultConfigByUserJIDResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetDefaultConfigByUserJIDResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetRolesByUserJIDString : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetRolesByUserJIDString *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetRolesByUserJIDStringResponse : NSObject {
	
/* elements */
	NSString * GetRolesByUserJIDStringResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetRolesByUserJIDStringResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetRolesByUserJIDStringResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_PadUser : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_PadUser *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_PadUserResponse : NSObject {
	
/* elements */
	NSString * PadUserResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_PadUserResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * PadUserResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetHospitalByUser : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetHospitalByUser *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetHospitalByUserResponse : NSObject {
	
/* elements */
	NSString * GetHospitalByUserResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetHospitalByUserResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetHospitalByUserResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetDepartmentsByHealthOrgID : NSObject {
	
/* elements */
	NSString * sHealthOrgID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetDepartmentsByHealthOrgID *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sHealthOrgID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetDepartmentsByHealthOrgIDResponse : NSObject {
	
/* elements */
	NSString * GetDepartmentsByHealthOrgIDResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetDepartmentsByHealthOrgIDResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetDepartmentsByHealthOrgIDResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetHospital : NSObject {
	
/* elements */
	NSString * sHealthOrgID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetHospital *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sHealthOrgID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetHospitalResponse : NSObject {
	
/* elements */
	NSString * GetHospitalResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetHospitalResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetHospitalResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetClerks : NSObject {
	
/* elements */
	NSString * sFielter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetClerks *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sFielter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetClerksResponse : NSObject {
	
/* elements */
	NSString * GetClerksResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetClerksResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetClerksResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetClertEx : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetClertEx *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetClertExResponse : NSObject {
	
/* elements */
	NSString * GetClertExResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetClertExResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetClertExResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetDataCenter : NSObject {
	
/* elements */
	NSString * sID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetDataCenter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetDataCenterResponse : NSObject {
	
/* elements */
	NSString * GetDataCenterResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetDataCenterResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetDataCenterResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_ArrayOfString : NSObject {
	
/* elements */
	NSMutableArray *string;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_ArrayOfString *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addString:(NSString *)toAdd;
@property (readonly) NSMutableArray * string;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_AuthorizeUserMenu : NSObject {
	
/* elements */
	WebMainService_ArrayOfString * Urls;
	NSString * sRoleCode;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_AuthorizeUserMenu *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) WebMainService_ArrayOfString * Urls;
@property (retain) NSString * sRoleCode;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_AuthorizeUserMenuResponse : NSObject {
	
/* elements */
	NSString * AuthorizeUserMenuResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_AuthorizeUserMenuResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * AuthorizeUserMenuResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetAllHospitals : NSObject {
	
/* elements */
	NSNumber * nDataCenterID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetAllHospitals *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * nDataCenterID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetAllHospitalsResponse : NSObject {
	
/* elements */
	NSString * GetAllHospitalsResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetAllHospitalsResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetAllHospitalsResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_DeleteClerk : NSObject {
	
/* elements */
	NSNumber * nID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_DeleteClerk *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * nID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_DeleteClerkResponse : NSObject {
	
/* elements */
	NSString * DeleteClerkResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_DeleteClerkResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * DeleteClerkResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_Get21CNClerk : NSObject {
	
/* elements */
	NSString * sHealthOrgID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_Get21CNClerk *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sHealthOrgID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_Get21CNClerkResponse : NSObject {
	
/* elements */
	NSString * Get21CNClerkResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_Get21CNClerkResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * Get21CNClerkResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_CreateRandomAuthorizeCode : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_CreateRandomAuthorizeCode *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_CreateRandomAuthorizeCodeResponse : NSObject {
	
/* elements */
	NSString * CreateRandomAuthorizeCodeResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_CreateRandomAuthorizeCodeResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * CreateRandomAuthorizeCodeResult;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetRandomAuthorizeCode : NSObject {
	
/* elements */
	NSString * sUserJID;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetRandomAuthorizeCode *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * sUserJID;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface WebMainService_GetRandomAuthorizeCodeResponse : NSObject {
	
/* elements */
	NSString * GetRandomAuthorizeCodeResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (WebMainService_GetRandomAuthorizeCodeResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * GetRandomAuthorizeCodeResult;
/* attributes */
- (NSDictionary *)attributes;
@end
/* Cookies handling provided by http://en.wikibooks.org/wiki/Programming:WebObjects/Web_Services/Web_Service_Provider */
#import <libxml/parser.h>
#import "xsd.h"
#import "WebMainService.h"
@class WebMainServiceSoapBinding;
@class WebMainServiceSoap12Binding;
@interface WebMainService : NSObject {
	
}
+ (WebMainServiceSoapBinding *)WebMainServiceSoapBinding;
+ (WebMainServiceSoap12Binding *)WebMainServiceSoap12Binding;
@end
@class WebMainServiceSoapBindingResponse;
@class WebMainServiceSoapBindingOperation;
@protocol WebMainServiceSoapBindingResponseDelegate <NSObject>
- (void) operation:(WebMainServiceSoapBindingOperation *)operation completedWithResponse:(WebMainServiceSoapBindingResponse *)response;
@end
@interface WebMainServiceSoapBinding : NSObject <WebMainServiceSoapBindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(WebMainServiceSoapBindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (WebMainServiceSoapBindingResponse *)HelloWorldUsingParameters:(WebMainService_HelloWorld *)aParameters ;
- (void)HelloWorldAsyncUsingParameters:(WebMainService_HelloWorld *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetMenusByUserRoleCNUsingParameters:(WebMainService_GetMenusByUserRoleCN *)aParameters ;
- (void)GetMenusByUserRoleCNAsyncUsingParameters:(WebMainService_GetMenusByUserRoleCN *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetDefaultConfigByUserJIDUsingParameters:(WebMainService_GetDefaultConfigByUserJID *)aParameters ;
- (void)GetDefaultConfigByUserJIDAsyncUsingParameters:(WebMainService_GetDefaultConfigByUserJID *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetRolesByUserJIDStringUsingParameters:(WebMainService_GetRolesByUserJIDString *)aParameters ;
- (void)GetRolesByUserJIDStringAsyncUsingParameters:(WebMainService_GetRolesByUserJIDString *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)PadUserUsingParameters:(WebMainService_PadUser *)aParameters ;
- (void)PadUserAsyncUsingParameters:(WebMainService_PadUser *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetHospitalByUserUsingParameters:(WebMainService_GetHospitalByUser *)aParameters ;
- (void)GetHospitalByUserAsyncUsingParameters:(WebMainService_GetHospitalByUser *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetDepartmentsByHealthOrgIDUsingParameters:(WebMainService_GetDepartmentsByHealthOrgID *)aParameters ;
- (void)GetDepartmentsByHealthOrgIDAsyncUsingParameters:(WebMainService_GetDepartmentsByHealthOrgID *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetHospitalUsingParameters:(WebMainService_GetHospital *)aParameters ;
- (void)GetHospitalAsyncUsingParameters:(WebMainService_GetHospital *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetClerksUsingParameters:(WebMainService_GetClerks *)aParameters ;
- (void)GetClerksAsyncUsingParameters:(WebMainService_GetClerks *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetClertExUsingParameters:(WebMainService_GetClertEx *)aParameters ;
- (void)GetClertExAsyncUsingParameters:(WebMainService_GetClertEx *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetDataCenterUsingParameters:(WebMainService_GetDataCenter *)aParameters ;
- (void)GetDataCenterAsyncUsingParameters:(WebMainService_GetDataCenter *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)AuthorizeUserMenuUsingParameters:(WebMainService_AuthorizeUserMenu *)aParameters ;
- (void)AuthorizeUserMenuAsyncUsingParameters:(WebMainService_AuthorizeUserMenu *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetAllHospitalsUsingParameters:(WebMainService_GetAllHospitals *)aParameters ;
- (void)GetAllHospitalsAsyncUsingParameters:(WebMainService_GetAllHospitals *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)DeleteClerkUsingParameters:(WebMainService_DeleteClerk *)aParameters ;
- (void)DeleteClerkAsyncUsingParameters:(WebMainService_DeleteClerk *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)Get21CNClerkUsingParameters:(WebMainService_Get21CNClerk *)aParameters ;
- (void)Get21CNClerkAsyncUsingParameters:(WebMainService_Get21CNClerk *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)CreateRandomAuthorizeCodeUsingParameters:(WebMainService_CreateRandomAuthorizeCode *)aParameters ;
- (void)CreateRandomAuthorizeCodeAsyncUsingParameters:(WebMainService_CreateRandomAuthorizeCode *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoapBindingResponse *)GetRandomAuthorizeCodeUsingParameters:(WebMainService_GetRandomAuthorizeCode *)aParameters ;
- (void)GetRandomAuthorizeCodeAsyncUsingParameters:(WebMainService_GetRandomAuthorizeCode *)aParameters  delegate:(id<WebMainServiceSoapBindingResponseDelegate>)responseDelegate;
@end
@interface WebMainServiceSoapBindingOperation : NSOperation {
	WebMainServiceSoapBinding *binding;
	WebMainServiceSoapBindingResponse *response;
	id<WebMainServiceSoapBindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) WebMainServiceSoapBinding *binding;
@property (readonly) WebMainServiceSoapBindingResponse *response;
@property (nonatomic, assign) id<WebMainServiceSoapBindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate;
@end
@interface WebMainServiceSoapBinding_HelloWorld : WebMainServiceSoapBindingOperation {
	WebMainService_HelloWorld * parameters;
}
@property (retain) WebMainService_HelloWorld * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_HelloWorld *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetMenusByUserRoleCN : WebMainServiceSoapBindingOperation {
	WebMainService_GetMenusByUserRoleCN * parameters;
}
@property (retain) WebMainService_GetMenusByUserRoleCN * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetMenusByUserRoleCN *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetDefaultConfigByUserJID : WebMainServiceSoapBindingOperation {
	WebMainService_GetDefaultConfigByUserJID * parameters;
}
@property (retain) WebMainService_GetDefaultConfigByUserJID * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetDefaultConfigByUserJID *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetRolesByUserJIDString : WebMainServiceSoapBindingOperation {
	WebMainService_GetRolesByUserJIDString * parameters;
}
@property (retain) WebMainService_GetRolesByUserJIDString * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetRolesByUserJIDString *)aParameters
;
@end
@interface WebMainServiceSoapBinding_PadUser : WebMainServiceSoapBindingOperation {
	WebMainService_PadUser * parameters;
}
@property (retain) WebMainService_PadUser * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_PadUser *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetHospitalByUser : WebMainServiceSoapBindingOperation {
	WebMainService_GetHospitalByUser * parameters;
}
@property (retain) WebMainService_GetHospitalByUser * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetHospitalByUser *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetDepartmentsByHealthOrgID : WebMainServiceSoapBindingOperation {
	WebMainService_GetDepartmentsByHealthOrgID * parameters;
}
@property (retain) WebMainService_GetDepartmentsByHealthOrgID * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetDepartmentsByHealthOrgID *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetHospital : WebMainServiceSoapBindingOperation {
	WebMainService_GetHospital * parameters;
}
@property (retain) WebMainService_GetHospital * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetHospital *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetClerks : WebMainServiceSoapBindingOperation {
	WebMainService_GetClerks * parameters;
}
@property (retain) WebMainService_GetClerks * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetClerks *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetClertEx : WebMainServiceSoapBindingOperation {
	WebMainService_GetClertEx * parameters;
}
@property (retain) WebMainService_GetClertEx * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetClertEx *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetDataCenter : WebMainServiceSoapBindingOperation {
	WebMainService_GetDataCenter * parameters;
}
@property (retain) WebMainService_GetDataCenter * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetDataCenter *)aParameters
;
@end
@interface WebMainServiceSoapBinding_AuthorizeUserMenu : WebMainServiceSoapBindingOperation {
	WebMainService_AuthorizeUserMenu * parameters;
}
@property (retain) WebMainService_AuthorizeUserMenu * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_AuthorizeUserMenu *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetAllHospitals : WebMainServiceSoapBindingOperation {
	WebMainService_GetAllHospitals * parameters;
}
@property (retain) WebMainService_GetAllHospitals * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetAllHospitals *)aParameters
;
@end
@interface WebMainServiceSoapBinding_DeleteClerk : WebMainServiceSoapBindingOperation {
	WebMainService_DeleteClerk * parameters;
}
@property (retain) WebMainService_DeleteClerk * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_DeleteClerk *)aParameters
;
@end
@interface WebMainServiceSoapBinding_Get21CNClerk : WebMainServiceSoapBindingOperation {
	WebMainService_Get21CNClerk * parameters;
}
@property (retain) WebMainService_Get21CNClerk * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_Get21CNClerk *)aParameters
;
@end
@interface WebMainServiceSoapBinding_CreateRandomAuthorizeCode : WebMainServiceSoapBindingOperation {
	WebMainService_CreateRandomAuthorizeCode * parameters;
}
@property (retain) WebMainService_CreateRandomAuthorizeCode * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_CreateRandomAuthorizeCode *)aParameters
;
@end
@interface WebMainServiceSoapBinding_GetRandomAuthorizeCode : WebMainServiceSoapBindingOperation {
	WebMainService_GetRandomAuthorizeCode * parameters;
}
@property (retain) WebMainService_GetRandomAuthorizeCode * parameters;
- (id)initWithBinding:(WebMainServiceSoapBinding *)aBinding delegate:(id<WebMainServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetRandomAuthorizeCode *)aParameters
;
@end
@interface WebMainServiceSoapBinding_envelope : NSObject {
}
+ (WebMainServiceSoapBinding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface WebMainServiceSoapBindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
@class WebMainServiceSoap12BindingResponse;
@class WebMainServiceSoap12BindingOperation;
@protocol WebMainServiceSoap12BindingResponseDelegate <NSObject>
- (void) operation:(WebMainServiceSoap12BindingOperation *)operation completedWithResponse:(WebMainServiceSoap12BindingResponse *)response;
@end
@interface WebMainServiceSoap12Binding : NSObject <WebMainServiceSoap12BindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(WebMainServiceSoap12BindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (WebMainServiceSoap12BindingResponse *)HelloWorldUsingParameters:(WebMainService_HelloWorld *)aParameters ;
- (void)HelloWorldAsyncUsingParameters:(WebMainService_HelloWorld *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetMenusByUserRoleCNUsingParameters:(WebMainService_GetMenusByUserRoleCN *)aParameters ;
- (void)GetMenusByUserRoleCNAsyncUsingParameters:(WebMainService_GetMenusByUserRoleCN *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetDefaultConfigByUserJIDUsingParameters:(WebMainService_GetDefaultConfigByUserJID *)aParameters ;
- (void)GetDefaultConfigByUserJIDAsyncUsingParameters:(WebMainService_GetDefaultConfigByUserJID *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetRolesByUserJIDStringUsingParameters:(WebMainService_GetRolesByUserJIDString *)aParameters ;
- (void)GetRolesByUserJIDStringAsyncUsingParameters:(WebMainService_GetRolesByUserJIDString *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)PadUserUsingParameters:(WebMainService_PadUser *)aParameters ;
- (void)PadUserAsyncUsingParameters:(WebMainService_PadUser *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetHospitalByUserUsingParameters:(WebMainService_GetHospitalByUser *)aParameters ;
- (void)GetHospitalByUserAsyncUsingParameters:(WebMainService_GetHospitalByUser *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetDepartmentsByHealthOrgIDUsingParameters:(WebMainService_GetDepartmentsByHealthOrgID *)aParameters ;
- (void)GetDepartmentsByHealthOrgIDAsyncUsingParameters:(WebMainService_GetDepartmentsByHealthOrgID *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetHospitalUsingParameters:(WebMainService_GetHospital *)aParameters ;
- (void)GetHospitalAsyncUsingParameters:(WebMainService_GetHospital *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetClerksUsingParameters:(WebMainService_GetClerks *)aParameters ;
- (void)GetClerksAsyncUsingParameters:(WebMainService_GetClerks *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetClertExUsingParameters:(WebMainService_GetClertEx *)aParameters ;
- (void)GetClertExAsyncUsingParameters:(WebMainService_GetClertEx *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetDataCenterUsingParameters:(WebMainService_GetDataCenter *)aParameters ;
- (void)GetDataCenterAsyncUsingParameters:(WebMainService_GetDataCenter *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)AuthorizeUserMenuUsingParameters:(WebMainService_AuthorizeUserMenu *)aParameters ;
- (void)AuthorizeUserMenuAsyncUsingParameters:(WebMainService_AuthorizeUserMenu *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetAllHospitalsUsingParameters:(WebMainService_GetAllHospitals *)aParameters ;
- (void)GetAllHospitalsAsyncUsingParameters:(WebMainService_GetAllHospitals *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)DeleteClerkUsingParameters:(WebMainService_DeleteClerk *)aParameters ;
- (void)DeleteClerkAsyncUsingParameters:(WebMainService_DeleteClerk *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)Get21CNClerkUsingParameters:(WebMainService_Get21CNClerk *)aParameters ;
- (void)Get21CNClerkAsyncUsingParameters:(WebMainService_Get21CNClerk *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)CreateRandomAuthorizeCodeUsingParameters:(WebMainService_CreateRandomAuthorizeCode *)aParameters ;
- (void)CreateRandomAuthorizeCodeAsyncUsingParameters:(WebMainService_CreateRandomAuthorizeCode *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
- (WebMainServiceSoap12BindingResponse *)GetRandomAuthorizeCodeUsingParameters:(WebMainService_GetRandomAuthorizeCode *)aParameters ;
- (void)GetRandomAuthorizeCodeAsyncUsingParameters:(WebMainService_GetRandomAuthorizeCode *)aParameters  delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)responseDelegate;
@end
@interface WebMainServiceSoap12BindingOperation : NSOperation {
	WebMainServiceSoap12Binding *binding;
	WebMainServiceSoap12BindingResponse *response;
	id<WebMainServiceSoap12BindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) WebMainServiceSoap12Binding *binding;
@property (readonly) WebMainServiceSoap12BindingResponse *response;
@property (nonatomic, assign) id<WebMainServiceSoap12BindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate;
@end
@interface WebMainServiceSoap12Binding_HelloWorld : WebMainServiceSoap12BindingOperation {
	WebMainService_HelloWorld * parameters;
}
@property (retain) WebMainService_HelloWorld * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_HelloWorld *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetMenusByUserRoleCN : WebMainServiceSoap12BindingOperation {
	WebMainService_GetMenusByUserRoleCN * parameters;
}
@property (retain) WebMainService_GetMenusByUserRoleCN * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetMenusByUserRoleCN *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetDefaultConfigByUserJID : WebMainServiceSoap12BindingOperation {
	WebMainService_GetDefaultConfigByUserJID * parameters;
}
@property (retain) WebMainService_GetDefaultConfigByUserJID * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetDefaultConfigByUserJID *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetRolesByUserJIDString : WebMainServiceSoap12BindingOperation {
	WebMainService_GetRolesByUserJIDString * parameters;
}
@property (retain) WebMainService_GetRolesByUserJIDString * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetRolesByUserJIDString *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_PadUser : WebMainServiceSoap12BindingOperation {
	WebMainService_PadUser * parameters;
}
@property (retain) WebMainService_PadUser * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_PadUser *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetHospitalByUser : WebMainServiceSoap12BindingOperation {
	WebMainService_GetHospitalByUser * parameters;
}
@property (retain) WebMainService_GetHospitalByUser * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetHospitalByUser *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetDepartmentsByHealthOrgID : WebMainServiceSoap12BindingOperation {
	WebMainService_GetDepartmentsByHealthOrgID * parameters;
}
@property (retain) WebMainService_GetDepartmentsByHealthOrgID * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetDepartmentsByHealthOrgID *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetHospital : WebMainServiceSoap12BindingOperation {
	WebMainService_GetHospital * parameters;
}
@property (retain) WebMainService_GetHospital * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetHospital *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetClerks : WebMainServiceSoap12BindingOperation {
	WebMainService_GetClerks * parameters;
}
@property (retain) WebMainService_GetClerks * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetClerks *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetClertEx : WebMainServiceSoap12BindingOperation {
	WebMainService_GetClertEx * parameters;
}
@property (retain) WebMainService_GetClertEx * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetClertEx *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetDataCenter : WebMainServiceSoap12BindingOperation {
	WebMainService_GetDataCenter * parameters;
}
@property (retain) WebMainService_GetDataCenter * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetDataCenter *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_AuthorizeUserMenu : WebMainServiceSoap12BindingOperation {
	WebMainService_AuthorizeUserMenu * parameters;
}
@property (retain) WebMainService_AuthorizeUserMenu * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_AuthorizeUserMenu *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetAllHospitals : WebMainServiceSoap12BindingOperation {
	WebMainService_GetAllHospitals * parameters;
}
@property (retain) WebMainService_GetAllHospitals * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetAllHospitals *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_DeleteClerk : WebMainServiceSoap12BindingOperation {
	WebMainService_DeleteClerk * parameters;
}
@property (retain) WebMainService_DeleteClerk * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_DeleteClerk *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_Get21CNClerk : WebMainServiceSoap12BindingOperation {
	WebMainService_Get21CNClerk * parameters;
}
@property (retain) WebMainService_Get21CNClerk * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_Get21CNClerk *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_CreateRandomAuthorizeCode : WebMainServiceSoap12BindingOperation {
	WebMainService_CreateRandomAuthorizeCode * parameters;
}
@property (retain) WebMainService_CreateRandomAuthorizeCode * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_CreateRandomAuthorizeCode *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_GetRandomAuthorizeCode : WebMainServiceSoap12BindingOperation {
	WebMainService_GetRandomAuthorizeCode * parameters;
}
@property (retain) WebMainService_GetRandomAuthorizeCode * parameters;
- (id)initWithBinding:(WebMainServiceSoap12Binding *)aBinding delegate:(id<WebMainServiceSoap12BindingResponseDelegate>)aDelegate
	parameters:(WebMainService_GetRandomAuthorizeCode *)aParameters
;
@end
@interface WebMainServiceSoap12Binding_envelope : NSObject {
}
+ (WebMainServiceSoap12Binding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface WebMainServiceSoap12BindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
