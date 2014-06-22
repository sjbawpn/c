#include "common.h"

BIO* bio_err = 0;
static char *pass;

static int password_cb(char *buf,int num,
  int rwflag,void *userdata)
  {
    if(num<strlen(pass)+1)
      return(0);

    strcpy(buf,pass);
    return(strlen(pass));
  }


/* Print SSL errors and exit*/
int berr_exit(char *string) {
    BIO_printf(bio_err,"%s\n",string);
    ERR_print_errors(bio_err);
    exit(0);
}

int err_exit(char *string)
  {
    fprintf(stderr,"%s\n",string);
    exit(0);
  }

void sigpipe_handle(int x) {

}
SSL_CTX *initialize_ctx(char* keyfile, char* password) {
    const SSL_METHOD *meth;
    SSL_CTX * ctx;
    if (!bio_err) {
        SSL_library_init();
        SSL_load_error_strings();
        
        /* An error write context */
        bio_err=BIO_new_fp(stderr, BIO_NOCLOSE);
    }
#ifndef __MINGW32__
    signal(SIGPIPE, sigpipe_handle);
#endif
    meth = SSLv23_method();
    ctx = SSL_CTX_new(meth);

    if (!(SSL_CTX_use_certificate_chain_file(ctx, keyfile)))
        berr_exit("Can't read certificate file");

    SSL_CTX_set_default_passwd_cb(ctx, password_cb);

    if(!(SSL_CTX_use_PrivateKey_file(ctx, keyfile, SSL_FILETYPE_PEM)))
        berr_exit("Can't read key file");
        
    if(!(SSL_CTX_load_verify_locations(ctx, CA_LIST, 0)))
        berr_exit("Can't read ca list");
    return ctx;
}
/*
int main(int argc, char* argv[]) {
    initialize_ctx("hello","world");
    return 1;
}
SL_CTX_load_verify_locations
*/
