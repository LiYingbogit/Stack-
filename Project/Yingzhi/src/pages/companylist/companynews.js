import React from 'react'
import { connect } from 'dva'
import { Carousl } from 'antd'
function CompanyNews() {
  return(
    <div>
      <li><a href="https://www.toutiao.com">今日头条</a></li>

    </div>
);

}
export default connect()(CompanyNews);
