import React from 'react';
import { connect } from 'dva';

function IndexPage() {
  return (
    <div >
       Welcome to dva!
    </div>
  );
}


IndexPage.propTypes = {
};


export default connect()(IndexPage);
