#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>


static char *
ngx_http_mytest(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static ngx_int_t ngx_http_mytest_handler(ngx_http_request_t *r);



static ngx_command_t  ngx_http_mytest_commands[] =
{

    {
        ngx_string("mytest"),
        NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_HTTP_LMT_CONF | NGX_CONF_NOARGS,
        ngx_http_mytest,
        NGX_HTTP_LOC_CONF_OFFSET,
        0,
        NULL
    },

    ngx_null_command
};

static ngx_http_module_t  ngx_http_mytest_module_ctx =
{
    NULL,                              /* preconfiguration */
    NULL,                  		/* postconfiguration */

    NULL,                              /* create main configuration */
    NULL,                              /* init main configuration */

    NULL,                              /* create server configuration */
    NULL,                              /* merge server configuration */

    NULL,       			/* create location configuration */
    NULL         			/* merge location configuration */
};

ngx_module_t  ngx_http_mytest_module =
{
    NGX_MODULE_V1,
    &ngx_http_mytest_module_ctx,           /* module context */
    ngx_http_mytest_commands,              /* module directives */
    NGX_HTTP_MODULE,                       /* module type */
    NULL,                                  /* init master */
    NULL,                                  /* init module */
    NULL,                                  /* init process */
    NULL,                                  /* init thread */
    NULL,                                  /* exit thread */
    NULL,                                  /* exit process */
    NULL,                                  /* exit master */
    NGX_MODULE_V1_PADDING
};


static char *
ngx_http_mytest(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t  *clcf;

    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔稿疆绾板瀚筸ytest闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱鐦″瀣儌lcf鐠ㄥ矂鏁撻弬銈嗗闁跨喐鏋婚幏绌昽cation闁跨喐鏋婚幏鐑芥晸閼哄倻顣幏鐑芥晸閺傘倖瀚归柨鐔告灮閹凤拷
//闁跨喓绮ㄩ弸鍕晸閺傘倖瀚归柨鐔告灮閹峰嘲鐤勯柨鐔告灮閹烽鍔ч柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风〇ain闁跨喐鏋婚幏绌漴v闁跨喐鏋婚幏鐑芥晸閺傘倖瀚筶oc闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喓鐡旈敍灞肩瘍闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭拠鎾晸閺傘倖瀚瑰В蹇涙晸閺傘倖瀚�
//http{}闁跨喐鏋婚幏绌漞rver{}闁跨喐鏋婚幏铚傜瘍闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规稉鈧柨鐔告灮閹风gx_http_core_loc_conf_t闁跨喓绮ㄩ弸鍕晸閺傘倖瀚�
    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);

    //http闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭拠鏍晸閺傘倖瀚归柨鐔告灮閹烽攱鐥呴柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閸欘偆顣幏绋瓽X_HTTP_CONTENT_PHASE闁跨喖妯佺拋瑙勫閺冨爼鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閿燂拷
//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撶徊瀛疘闁跨喐鏋婚幏绌杫test闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喕濡喊澶嬪闁跨喐鏋婚幏鐑芥晸閻偄灏呴幏鐑芥晸閺傘倖瀚归崠褰掓晸閹存帪绱濋柨鐔煎徍閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�
//鐎圭偤鏁撶悰妤冾暜閹风gx_http_mytest_handler闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻敓锟�
    clcf->handler = ngx_http_mytest_handler;

    return NGX_CONF_OK;
}


static ngx_int_t ngx_http_mytest_handler(ngx_http_request_t *r)
{
    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风ěET闁跨喐鏋婚幏鐑芥晸閺傘倖瀚笻EAD闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐瑙︽潻鏂剧串閹凤拷405 Not Allowed
    if (!(r->method & (NGX_HTTP_GET | NGX_HTTP_HEAD)))
    {
        return NGX_HTTP_NOT_ALLOWED;
    }

    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喎褰ㄩ惃鍕簻閹风兘鏁撻弬銈嗗
    ngx_int_t rc = ngx_http_discard_request_body(r);
    if (rc != NGX_OK)
    {
        return rc;
    }

    //闁跨喐鏋婚幏鐑芥晸閻偄鍤栭幏鐑芥晸閹搭亞顣幏绋ntent-Type闁跨喐鏋婚幏閿嬫暈闁跨喕袙閿涘gx_str_t闁跨喐鏋婚幏铚傜闁跨喐鏋婚幏鐑芥晸閺夋澘鍤栭幏鐑芥晸閺傘倖瀚归弻鎰版晸缂佺偟銆嬮幏鐑芥晸閺傘倖瀚归柨鐕傛嫹
//ngx_string闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻惃鍡楀簻閹风gx_str_t闁跨喐鏋婚幏绌宎ta闁跨喐鏋婚幏绌昬n闁跨喐鏋婚幏宄版喅闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹叓閻氬瓨瀚�
    ngx_str_t type = ngx_string("text/plain");
    //闁跨喐鏋婚幏鐑芥晸閹搭亞娈戠敮顔藉闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹凤拷
    ngx_str_t response = ngx_string("Hello World!");
    //闁跨喐鏋婚幏鐑芥晸閻偄鍤栭幏鐑芥晸閺傘倖瀚归悩鑸碘偓渚€鏁撻弬銈嗗
    r->headers_out.status = NGX_HTTP_OK;
    //闁跨喐鏋婚幏宄扮安闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔峰建鐢喗瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐宓庨惃鍕剁秶閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭憰渚€鏁撻弬銈嗗闁跨喐鏋婚幏绋ntent-Length闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�
    r->headers_out.content_length_n = response.len;
    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚笴ontent-Type
    r->headers_out.content_type = type;

    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚筯ttp婢舵挳鏁撻弬銈嗗
    rc = ngx_http_send_header(r);
    if (rc == NGX_ERROR || rc > NGX_OK || r->header_only)
    {
        return rc;
    }

    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚筺gx_buf_t闁跨喓绮ㄩ弸鍕櫙闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔煎徍鐢喗瀚归柨鐔告灮閹凤拷
    ngx_buf_t                 *b;
    b = ngx_create_temp_buf(r->pool, response.len);
    if (b == NULL)
    {
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }
    //闁跨喐鏋婚幏绋╡llo World闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风gx_buf_t閹稿洭鏁撻弬銈嗗闁跨喐鏋婚幏鐤槺闁跨喐鏋婚幏鐑芥晸閿燂拷
    ngx_memcpy(b->pos, response.data, response.len);
    //濞夈劑鏁撶憴锝忕礉娑撯偓闁跨喐鏋婚幏鐤洣闁跨喐鏋婚幏鐑芥晸閻偆灏ㄩ幏绌昦st閹稿洭鏁撻弬銈嗗
    b->last = b->pos + response.len;
    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閹活厺绱幏閿嬵渶閻氬瓨瀚归柨鐔告灮閹风兘鏁撻敓锟�
    b->last_buf = 1;

    //闁跨喐鏋婚幏鐑芥晸鐏炲﹤褰傞柨鐔告灮閹烽攱妞傞柨鐔告灮閹风gx_chain_t闁跨喓绮ㄩ弸鍕晸閺傘倖瀚�
    ngx_chain_t		out;
    //闁跨喐鏋婚幏宄扳偓绯縢x_buf_t
    out.buf = b;
    //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚筺ext娑撶瘶ULL
    out.next = NULL;

    //闁跨喐鏋婚幏鐑芥晸閹活厺绱幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱銆婇柨鐔告灮閹烽攱绔熼悶鐪泃p闁跨喐鏋婚幏鐤闁跨喐鏋婚幏鐑芥晸閺傘倖瀚筺gx_http_finalize_request闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�
//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗
    return ngx_http_output_filter(r, &out);
}


