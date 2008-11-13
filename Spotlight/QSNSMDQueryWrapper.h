//
//  QSMDFindWrapper.h
//  QSSpotlightPlugIn
//
//  Created by Nicholas Jitkoff on 3/21/05.
//  Copyright 2005 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface QSNSMDQueryWrapper : NSObject {
	NSString *query;
	NSString *path;
	NSMutableArray *results;
	BOOL keepalive;
	NSMetadataQuery *mdquery;
	NSMutableString *resultPaths;
}
+ findWrapperWithQuery:(NSString *)aQuery path:(NSString *)aPath keepalive:(BOOL)keepAlive;
- (void)startQuery;
- (NSMutableArray *)results;

@end
