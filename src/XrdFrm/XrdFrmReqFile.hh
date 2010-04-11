#ifndef __FRMREQFILE_H__
#define __FRMREQFILE_H__
/******************************************************************************/
/*                                                                            */
/*                      X r d F r m R e q F i l e . h h                       */
/*                                                                            */
/* (c) 2010 by the Board of Trustees of the Leland Stanford, Jr., University  */
/*                            All Rights Reserved                             */
/*   Produced by Andrew Hanushevsky for Stanford University under contract    */
/*              DE-AC02-76-SFO0515 with the Department of Energy              */
/******************************************************************************/

//          $Id$

#include "XrdFrm/XrdFrmRequest.hh"

class XrdFrmReqFile
{
public:

       void   Add(XrdFrmRequest *rP);

       void   Can(XrdFrmRequest *rP);

       void   Del(XrdFrmRequest *rP);

       int    Get(XrdFrmRequest *rP);

       int    Init();

enum Item {getLFN=0, getLFNCGI, getMODE, getNOTE, getOP, getPRTY, getQWT,
           getRID,   getTOD,    getUSER};

       char  *List(char *Buff, int bsz, int &Offs, Item *ITList=0, int ITNum=0);

       void   ListL(XrdFrmRequest tmpReq, char *Buff, int bsz,
                    Item *ITList, int ITNum);

static int    Unique(const char *lkfn);

              XrdFrmReqFile(const char *fn);
             ~XrdFrmReqFile() {}

private:
enum LockType {lkNone, lkShare, lkExcl, lkInit};

static const int ReqSize  = sizeof(XrdFrmRequest);

void   FailAdd(char *lfn, int unlk=1);
void   FailCan(char *rid, int unlk=1);
void   FailDel(char *lfn, int unlk=1);
int    FailIni(const char *lfn);
int    FileLock(LockType ltype=lkExcl);
int    reqRead(void *Buff, int Offs);
int    reqWrite(void *Buff, int Offs, int updthdr=1);

struct FileHdr
{
int    First;
int    Last;
int    Free;
}      HdrData;

char  *lokFN;
int    lokFD;
int    reqFD;
char  *reqFN;

struct recEnt {recEnt       *Next;
               XrdFrmRequest reqData;
               recEnt(XrdFrmRequest &reqref) {Next = 0; reqData = reqref;}
              };
int    ReWrite(recEnt *rP);
};
#endif
