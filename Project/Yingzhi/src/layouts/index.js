import React ,{ Component }from 'react'
import { Layout, Menu } from 'antd';
import withRouter from 'umi/withRouter';
import Link from 'umi/link';
const { Header, Content, Footer } = Layout;

const AllLayout =({ children })=>{

  return (
    <Layout className="layout">
      <Header>
        <div className="logo"/>
        <Menu
          theme="dark"
          mode="horizontal"
          defaultSelectedKeys={['1']}
          style={{ lineHeight: '64px' }}
        >
          <Menu.Item key="1"><Link to ="/companylist/companyintroduce">公司简介</Link></Menu.Item>
          <Menu.Item key="2"><Link to ="/companylist/companynews">今日头条</Link></Menu.Item>
          <Menu.Item key="3"><Link to="/companylist/companyphone">联系我们</Link></Menu.Item>
        </Menu>
      </Header>
      <Content style={{ padding: '0 50px' }}>
        <div style={{ background: '#fff', padding: 24, minHeight: 280 }}>
          {children}
        </div>
      </Content>
      <Footer style={{ textAlign: 'center' }}>
        Ant Design ©2018 Created by  LYB
      </Footer>
    </Layout>
  )

}



export default AllLayout;



