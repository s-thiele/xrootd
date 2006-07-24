# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.
package XrdClientAdmin;
require Exporter;
require DynaLoader;
@ISA = qw(Exporter DynaLoader);
package XrdClientAdminc;
bootstrap XrdClientAdmin;
package XrdClientAdmin;
@EXPORT = qw( );

# ---------- BASE METHODS -------------

package XrdClientAdmin;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub FIRSTKEY { }

sub NEXTKEY { }

sub FETCH {
    my ($self,$field) = @_;
    my $member_func = "swig_${field}_get";
    $self->$member_func();
}

sub STORE {
    my ($self,$field,$newval) = @_;
    my $member_func = "swig_${field}_set";
    $self->$member_func($newval);
}

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package XrdClientAdmin;

*XrdInitialize = *XrdClientAdminc::XrdInitialize;
*XrdTerminate = *XrdClientAdminc::XrdTerminate;
*XrdSysStatX = *XrdClientAdminc::XrdSysStatX;
*XrdExistFiles = *XrdClientAdminc::XrdExistFiles;
*XrdExistDirs = *XrdClientAdminc::XrdExistDirs;
*XrdIsFileOnline = *XrdClientAdminc::XrdIsFileOnline;
*XrdMv = *XrdClientAdminc::XrdMv;
*XrdMkdir = *XrdClientAdminc::XrdMkdir;
*XrdChmod = *XrdClientAdminc::XrdChmod;
*XrdRm = *XrdClientAdminc::XrdRm;
*XrdRmdir = *XrdClientAdminc::XrdRmdir;
*XrdPrepare = *XrdClientAdminc::XrdPrepare;
*XrdDirList = *XrdClientAdminc::XrdDirList;
*XrdGetChecksum = *XrdClientAdminc::XrdGetChecksum;
*XrdGetCurrentHost = *XrdClientAdminc::XrdGetCurrentHost;
*XrdStat = *XrdClientAdminc::XrdStat;

# ------- VARIABLE STUBS --------

package XrdClientAdmin;

1;
