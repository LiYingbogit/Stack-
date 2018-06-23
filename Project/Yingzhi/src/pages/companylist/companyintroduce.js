import React from 'react';
import { connect } from 'dva';

function CompanyIntroduction() {
  return (
    <div >
      <h1>北京旷视科技</h1>
      你知道我对你不仅仅是喜欢，眼中却没有我想要的答案，这样若即若离让我很抓狂~
      你知道我对你不仅仅是喜欢，想要和你去很远的地方，看阳光在路上撒下了浪漫，当做我对你表白吧~
      不要想你只是习惯，不满足每天的晚安，我要你留恋我在你身旁，爱我像我爱你一样 ~

    </div>
  );
}


CompanyIntroduction.propTypes = {
};


export default connect()(CompanyIntroduction);
